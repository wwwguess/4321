// referee.c

inherit NPC;
#include <ansi.h>

int do_bihua(string arg);
string ask_me();
int do_halt();
int do_vliad();
void create()
{
	set_name("��ƽ��", ({ "Gongping zi","gongping zi", "zi", "referee" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
	set("combat_exp",600000);
        set("per", 27);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("inquiry", ([
		"������"       : (: ask_me :),
	]));

	setup();
          carry_object("/obj/weapon/sword")->wield();
          carry_object("/obj/cloth/cloth")->wear();

}


void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
	add_action("do_vliad", "conjure");
	add_action("do_vliad", "pray");
	add_action("do_vliad", "dancing");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_bihua", "kill");
	add_action("do_halt",  "halt");
        add_action("do_halt",  "h");
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "����Ȩ�ٿ������ᣡ\n";

	for ( i=sizeof(ob); i>0; i-- ) {
	    if (ob[i-1]->query("age")<16) continue;
		ob[i-1]->set("mark/bwdh",1);
		ob[i-1]->move("/d/taishan/biwutai");
	}

	return "�ã����ڱ�������ʽ��ʼ��ȫ�弯�ϣ�\n";
}

int do_bihua(string arg)
{     
	object ob1, ob2;
        object old_target;

	ob1 = this_player();
        if( ob1->query("mark/bwdh") == 0 )
        {
             tell_object (ob1, "��ƽ��˵������û�о��б����ᣬ��ذɡ�\n");
        }
        if( ob1->query("mark/bwdh") == 2 )
            {
 return notify_fail("��ƽ��˵,���Ѿ���������̨,�´α�����������.\n");
            }    
        
	if( !arg || arg=="" ) return 0;  

	if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
           {
             command("say " + "�㲻�ܸ��ұȻ���\n");
             return 1;
            }

	if ( this_object()->query_temp("busy") ) 
		return notify_fail("ÿ��ֻ�������˲μӱ��䡣\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
		return notify_fail("�����˭�Ȼ���\n");
        if (ob1 == ob2)    return notify_fail("�㲻�ܹ����Լ���\n");


	if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(ob1) 
			+ ob1->name() + "���"
			+ RANK_D->query_respect(ob2) + "�ĸ��Т�\n\n", ob1, ob2);
		if( objectp(old_target = ob1->query_temp("pending/fight")) )
			tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		ob1->set_temp("pending/fight", ob2);
		tell_object(ob2, YEL "�����Ը��ͶԷ����б���,����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� bihua ָ�\n" NOR);

		write(YEL "��춶Է�������ҿ��Ƶ�����,�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}
	    
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

	remove_call_out("check");
	call_out("check",0, ob1, ob2);

	ob1->set("kee",(int)ob1->query("max_kee"));
	ob2->set("kee",(int)ob2->query("max_kee"));

	remove_call_out("fighting");
	call_out("fighting",2, ob1, ob2);

	return 1;
}

void fighting(object me, object ob)
{
        int mycor, obcor, mykee, obkee, myeff_kee, obeff_kee;
        int turn, flag, i, j, k, l, flag1 = 0;
        float count, count_total = 0.0;

        if (!ob || ob == me)    return;
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
        //delay
	 for (i=1;i<30000;i++);
	}
	call_out("observe",1,me,ob);
}

void check(object ob1, object ob2)
{
	this_object()->set_temp("busy",1);
	command("chat " + ob1->query("name") 
		+ "��" + ob2->query("name") + "�����ڿ�ʼ�����۽���\n");
	call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
	object ob;
	int mykee,myeff_kee,obkee,obeff_kee,pjkee;
	int flag1=2;

	pjkee = ob1->query("max_kee")/10 + ob2->query("max_kee")/10;

	if(ob1->is_fighting()) 
	{
		call_out("observe",1,ob1,ob2);
		return 1;
	}
        // 2.check if can continue
                mykee = ob1->query("kee");
                myeff_kee = ob1->query("eff_kee");
                obkee = ob2->query("kee");
                obeff_kee = ob2->query("eff_kee");
                if (mykee <= 0) {
                        ob1->set("kee", 10);
                        flag1 = 1;
                        }
                if (myeff_kee <= 0) {
                        ob1->set("eff_kee", 10);
                        flag1 = 1;
                        }
                if (obkee <= 0) {
                        ob2->set("kee", 10);
                        flag1 = 0;
                        }
                if (obeff_kee <= 0) {
                        ob2->set("eff_kee", 10);
                        flag1 = 0;
                        }                   

	this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

	if ( flag1==1 ) 
	{
		ob1->delete_temp("marks/bwdh");
		command("chat " + ob1->query("name") + "��"+
		ob2->query("name")+"���ܡ�\n");
		ob1->set("mark/bwdh",2);
//		ob1->move("/d/taishan/riguan");
		return 1;
	}

	if ( flag1==0 ) 
	{
		ob2->delete_temp("marks/bwdh");
		command("chat " + ob2->query("name") + "��"+
		ob1->query("name")+"���ܡ�\n");
		ob2->set("mark/bwdh",2);
//		ob2->move("/d/taishan/riguan");
		return 1;
	}

        if ( !present(ob1, environment()) ) 
        {
                command("chat " + ob1->query("name") + "��Ķ����ˣ�\n");
                return 1;
        }

        if ( !present(ob2, environment()) ) 
        {
                command("chat " + ob2->query("name") + "��Ķ����ˣ�\n");
                return 1;
        }
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("chat " + ob1->query("name") + 
                       "��;�������䣡\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") + 
                       "��;�������䣡\n");
                return 1;
         }

	if ( mykee > obkee) 
	{
  	   if  ((mykee - obkee) < pjkee ) 
	    {
		   command("chat " + ob1->query("name") 
			+ "��" + ob2->query("name") + "���䲻��ʤ����\n");
	 	   return 1;
    	    }
		command("chat " + ob1->query("name") 
			+ "����սʤ" + ob2->query("name") + "��\n");
		ob = new("/obj/money/thousand-cash");
		ob->move(ob1);
		ob2->set("mark/bwdh",2);
//		ob2->move("/d/taishan/riguan");
	}
	else
	{
           if  ((obkee - mykee) < pjkee )
                {
                   command("chat " + ob1->query("name")
                        + "��" + ob2->query("name") + "���䲻��ʤ����\n");
                   return 1;
                }    
		command("chat " + ob2->query("name") 
			+ "����սʤ" + ob1->query("name") + "��\n");
		ob = new("/obj/money/thousand-cash");
		ob->set_amount(2);
		ob->move(ob2);
		ob1->set("mark/bwdh",2);
//		ob1->move("/d/taishan/riguan");
	}
	return 1;

}
int do_vliad()
{
 object me = this_player();
 me->set("mark/bwdh",0);
return 1;  
}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}
