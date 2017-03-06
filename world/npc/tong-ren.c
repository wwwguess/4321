// tong-ren.c ͭ��

inherit NPC;
//inherit F_CLEAN_UP;

void create()
{
	set_name("ͭ��", ({ "tong ren","tong","ren"}) );
	set("gender", "����" );
	set("age", 30);
	set_weight(200000);
	set("long", "һ�������õı���ͭ�ˣ��������ɣ���ͬ����һ�㡣\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 2000);
	set("eff_kee", 2000);
	set("kee", 2000);
	set("max_gin", 800);
	set("gin", 800);
	set("max_gin", 800);
	set("eff_gin", 800);
	set("gin", 800);
	set("max_sen", 800);
	set("eff_sen", 800);
	set("sen", 800);

	set("max_force", 1000);
	set("force", 1000);


	set("combat_exp", 100000);

	set_skill("force", 80); 
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

//	set("fight_times", 0);	

	setup();
        
	carry_object("/obj/longsword");
	carry_object("/obj/blade");
	carry_object("/obj/cloth")->wear();

}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

/*	if (me->query("damaged"))
		return notify_fail("���ͭ���Ѿ������ˣ�\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("���ͭ���Ѿ������ˣ�\n");	
	}
*/
	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("��ո����ͭ����������\n");		

	me->set("last_fighter", ob->query("id"));
//	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 60 , me);	

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
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
			me->set_skill(sname[i], (int)(skill_status[sname[i]]));
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
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_gin",  hp_status["max_gin"]);
		me->set("eff_gin",  hp_status["eff_gin"]);
		me->set("gin",      hp_status["gin"]);
		me->set("max_sen",  hp_status["max_sen"]);
		me->set("eff_sen",  hp_status["eff_sen"]);
		me->set("sen",      hp_status["sen"]);
//		me->set("max_kee",   2000);
//		me->set("eff_kee",   2000);
//		me->set("kee",       2000);
//		me->set("max_gin",  800);
//		me->set("eff_gin",  800);
//		me->set("gin",      800);
		me->set("max_force", hp_status["max_force"]);
		me->set("force",     hp_status["force"]);
		me->set("force_factor",     hp_status["force_factor"]);
		me->set("combat_exp",(int)(hp_status["combat_exp"]));

	return 1;
}

void init()
{
	add_action("do_wield", "weapon");
	add_action("do_unwield", "unweapon");
}


void renewing(object me)
{
	me->delete("last_fighter");
}

int do_wield(string arg)
{
	object me = this_object();
	object obj;
	string str;

	if(!arg)
		return notify_fail("װ��ʲô��\n");

	if( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( obj->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	if( obj->wield() ) {
		if( !stringp(str = obj->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
		message_vision(str, me, obj);
		return 1;
	} 

	return 0;
}


int do_unwield(string arg)
{
	object me = this_object();
	object ob;
	string str;

	if( !arg ) return notify_fail("��Ҫж��ʲ��װ����\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("�㲢û��װ������������Ϊ������\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}
