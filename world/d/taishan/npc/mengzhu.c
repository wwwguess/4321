// meng-zhu.c ��������

//#ifndef NPCDATA
//#define NPCDATA "/data/npc/"
//#endif
//#define MENGZHU NPCDATA + "meng-zhu"

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
//inherit F_UNIQUE;
inherit F_SAVE;
#define MEWIN	1
#define OBWIN	2

string query_save_file()
{
	return "/data/menzhu";

}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("��������", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
	set("title", "��������" );
	set("gender", "����" );
	set("age", 40);
      set("long","�������۾����֣��������£�����պյĵ�������������\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("cor", 25);

	set("max_kee", 500);
	set("eff_kee", 500);
	set("kee", 500);
	set("max_gin", 300);
	set("gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 40);
	set("per", 0);

	set("no_clean_up",1);
	set("combat_exp", 500000);

	set_skill("force",  100); 
	set_skill("unarmed",100);
	set_skill("sword",  100);
	set_skill("dodge",  100);
	set_skill("parry",  100);

	//set("weapon", "/obj/changjian");
	//set("armor", "/d/city/obj/cloth");

	setup();
	//carry_object("/d/shaolin/obj/changjian")->wield();
	//carry_object("/d/city/obj/cloth")->wear();        
	}
	else {
		set("id", "mengzhu");
		set_name(query("name"), ({ query("id") }));
		setup();
		if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
		if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();        
	}
}

void init()
{
	object me = this_object();

	add_action("do_recopy",  "recopy");
	add_action("do_recover", "recover");
	add_action("do_kill", "kill");
        add_action("do_kill", "order");
        add_action("do_biwu", "fight");
  add_action("do_kill","exert");

}
void start_biwu(object me, object ob)
{
        int mycor, obcor, mykee, obkee, myeff_kee, obeff_kee;
        int turn, flag, i, j, k, l, flag1 = 0;
        float count, count_total = 0.0;

        if (!ob || ob == me)    return;
 //    check if have some one use this bug to add combat_exp
        mykee = me->query("kee");       
	obkee = ob->query("kee");
	obeff_kee =(int) ob->query("eff_kee");
	myeff_kee =(int) me->query("eff_kee");
        if(mykee==1||obkee==1) return;
        if(mykee<=myeff_kee/10||obkee<=obeff_kee/10) return;
        // check cor, decide attack turns
        mycor = me->query_cor();
        obcor = ob->query_cor();
        if (mycor > obcor) {
                turn = mycor / obcor;
                count = (float) mycor / (float) obcor - turn;
                flag = 0;
                }
            else {
                turn = obcor / mycor;
                count = (float) obcor / (float) mycor - turn;
                flag = 1;
                }


        // attack until one failed
        for (;;) {
        // 1. fight
                if (!flag) {
                        for (i=0; i<= (turn+1)/2; i++)
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                        count_total = count_total + count/2;
                        if (count_total > 1.) {
                          COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                                count_total = count_total - 1.;
                                }
                        }
                    else {
                        for (i=0; i<= (turn+1)/2; i++)
                        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                        count_total = count_total + count/2;
                        if (count_total > 1.) {
                          COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
                                count_total = count_total - 1.;
                                }
                        }

        // 2.check if can continue
                mykee = me->query("kee");
		myeff_kee = me->query("eff_kee");
                obkee = ob->query("kee");
		obeff_kee = ob->query("eff_kee");
                if (mykee <= 0) {
                        me->set("kee", 1);
			flag1 = MEWIN;
			}
		if (myeff_kee <= 0) {
			me->set("eff_kee", 1);
			flag1 = MEWIN;
			}
                if (obkee <= 0) {
                        ob->set("kee", 1);
			flag1 = OBWIN;
			}
		if (obeff_kee <= 0) {
			ob->set("eff_kee", 1);
			flag1 = OBWIN;
			}
		if (flag1 == MEWIN) {
			message_vision("$N���˹��֣�˵���������书����������������\n", me);
			return;
			}
		    else if (flag1 == OBWIN) {
                        message_vision("$N���˹��֣�˵���������书����������������\n", ob);
                        return;
                        }
		
	// delay
/*		for (j=0; j<50;j ++)
			for (k=0; k<50; k++)
				for (l=0; l<50; l++);
 */       }
}



int do_kill()
{
	object ob;
	int i;

	command("say ��Ҫ��������Խ�����fight����");
	//command("say ���°�����ʿ���ڣ�");
	
	//message_vision("���ܵİ�����ʿȺ���$N����������\n", this_player());

	//for(i=0; i<4; i++) {
		if( objectp( ob = present("wei shi " + (i+1), environment(this_object())) ) )
				 ob->kill_ob(this_player());	
	//	else	this_object()->kill_ob(this_player());		
	//}

	return 1;
}

int do_biwu()
{        object me,ob;
        string aa;   
  seteuid(getuid());     
 ob=this_player();
        
 me  = this_object();

		
	if ( me->query("winner") == ob->query("id") ) 
		return notify_fail("������Լ���ʲô�ܣ���\n");

      if (wizardp(this_player()))
		return notify_fail("��ʦ����������֮λ��\n");

	if ( me->is_fighting() ) 
		return notify_fail("�Ѿ�����������ս����������\n");

	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("gin",   me->query("max_gin"));
	me->set("force",  me->query("max_force"));
       	message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(ob) + "�ĸ��У�\n\n", me, ob);
         start_biwu(me,ob);
       remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}


int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_kee");
	his_max_qi = ob->query("max_kee");

	if (me->is_fighting()) {
		if ( (me->query("kee")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if ((int)me->query("kee")== 1 ) {
		command("say ��Ȼ��������ϲ���Ϊ��������������\n");
		command("chat �������������ǳ���������ǰ�ˣ�һ�����˻����ˣ�\n");
		command("chat ��ϲ" + ob->query("name") + "���ƾ�Ϊ��������������\n");
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if ( ((int)ob->query("kee")==1||(int)ob->query("kee")<=(int)ob->query("eff_kee")/10) )
	 {
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڵ��������г���ͷ�� !\n");
		return 1;
	}

	return 1;  
}

int do_copy(object me, object ob)
{
	object ob1, ob2;
	string mengzhu, shangshan, fae;

	seteuid(getuid());

	me->set("winner", ob->query("id"));
	me->add("generation", 1);	

	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short()}));
	
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");
	me->delete("title");

/*	if(!( ob1 = find_living("shangshan")) )
	ob1 = load_object("/clone/npc/shang-shan");
	shangshan = ob1->query("winner");

	if(!( ob2 = find_living("fae")) )
	ob2 = load_object("/clone/npc/fa-e");
	fae = ob1->query("winner");

	if( ob->query("id") == shangshan ) {
		rm( ob1->query_save_file() + __SAVE_EXTENSION__);
		destruct(ob1);
	}
	else  if( ob->query("id") == fae ) {
		rm( ob2->query_save_file() + __SAVE_EXTENSION__ );
		destruct(ob2);
	}
*/
	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_recopy(object me, object ob)
{
	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");

	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short()}));

	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");
	me->delete("title");

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_clone(object me, object ob)
{	
      	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;
        object *inv,new11;
  
	seteuid( geteuid(me) );

///* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) )
 {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */
	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
	//	if( inv[i]->query("weapon_prop/damage") > 100 
	//	||  inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("cor", hp_status["dex"]);
		me->set("age", hp_status["age"]);
		me->set("per", hp_status["per"]);

                me->set("max_sen",    hp_status["max_sen"]);
                me->set("eff_sen",    hp_status["eff_sen"]);
                me->set("sen",        hp_status["sen"]);      
		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_gin",  hp_status["max_gin"]);
		me->set("eff_gin",  hp_status["eff_gin"]);
		me->set("gin",      hp_status["gin"]);
		me->set("max_force", hp_status["max_force"]);
		me->set("force",     hp_status["force"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);
                me->set("mana",      hp_status["mana"]);
                me->set("max_mana", hp_status["max_mana"]);
                me->set("atman",     hp_status["atman"]);
                me->set("max_atman",     hp_status["max_atman"]);
                me->set("potential",    hp_status["potential"]);     
	save();

	tell_object(ob, "״̬������ϡ�\n");

	new11 = new("/data/mengzhu");
	new11->move("/d/taishan/fengchan");
	destruct(me);

	return 1;
}

int do_recover()
{
	object me, ob;
	mapping skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");;

/* delete and copy skills */

	if ( mapp(skill_status = ob->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			ob->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			ob->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* copy combat exp values */

	ob->set("combat_exp", me->query("combat_exp"));

	write("״̬��Ԫ��ϡ�\n");

	return 1;
}

