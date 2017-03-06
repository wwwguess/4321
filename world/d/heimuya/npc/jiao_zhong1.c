// jiao_zhong1.c
//write by dfbb@hero
//
#include <ansi.h>
inherit NPC;

#include <random_name.h>


void kailiu();

void create()
{
        string name,id,nick;

	name = get_rndname();
	id = get_rndid();
	nick = get_rndnick();
	
        set_name(name, ({ id, "jiaozhong" }) );
	set("gender", "����");
        set("title",HIR "��"+HIB"��"+HIY "���" NOR + "����");
        set("nickname", nick);

	set("age", 20);
	set("long",
		"��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 15000+random(15000));
        set("shen_type", -1);
	set("attitude", "heroism");
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: kailiu :),
		(HIY "ʥ����ǧ�����أ�һͳ����!\n" NOR),
		(HIG "�ĳ���¡��󱻲���ʥ��������������!\n" NOR),
        }) );


	set_skill("unarmed", 45);
	set_skill("parry", 40);
	set_skill("dodge", 40);

        create_family("�������", 16, "����");


	setup();
        
	if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/sword")->wield();
	  set_skill("sword",40);
	  set_skill("mo-jian-jue",40);
	  map_skill("sword","mo-jian-jue");
	 }	
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/blade")->wield();
	  set_skill("blade",40);
          set_skill("mo-dao-jue",40);
          map_skill("blade","mo-dao-jue");
	 }
        else if(strsrch(nick,"��")!=-1)
	 {
	  carry_object("/d/heimuya/obj/gou")->wield();
          set_skill("gou",40);
          set_skill("mo-gou-jue",40);
          map_skill("gou","mo-gou-jue");
         }
        else if(strsrch(nick,"�")!=-1)
	 {
	  carry_object("/d/heimuya/obj/ji")->wield();
          set_skill("ji",40);
          set_skill("mo-ji-jue",40);
          map_skill("ji","mo-ji-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
	 carry_object("/d/heimuya/obj/hammer")->wield();
	 set_skill("hammer",40);
         set_skill("mo-chui-jue",40);   
         map_skill("hammer","mo-chui-jue");
         }

        else if(strsrch(nick,"��")!=-1)
	 {
	  carry_object("/d/heimuya/obj/axe")->wield();
          set_skill("axe",40);
          set_skill("mo-fu-jue",40);
          map_skill("axe","mo-fu-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
         carry_object("/d/heimuya/obj/fork")->wield();
         set_skill("fork",40);
         set_skill("mo-cha-jue",40);   
         map_skill("fork","mo-cha-jue");
         }

        else if(strsrch(nick,"ǹ")!=-1)
	 {
	  carry_object("/d/heimuya/obj/qiang")->wield();
          set_skill("qiang",40);
          set_skill("mo-qiang-jue",40);
          map_skill("qiang","mo-qiang-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/whip")->wield();
	  set_skill("whip",40);
          set_skill("mo-bian-jue",40);
          map_skill("whip","mo-bian-jue");
         }
	else 
	 {
  	  set_skill("mo-zhang-jue",40);
          map_skill("unarmed","mo-zhang-jue");
	 }

        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
        add_action("do_gogo", "go");
        add_action("do_none", "north");
	::init();
}

int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( (arg == "north" )&&(!query("is_here")))
        {
                if( me->query("shen") ) 
                if( me->query("shen") >= 200) {
        command("grin");
        command("say �����ְ׵��ϵ����ﵽ�����ʲô?������!!");
        write("��������·������ס�� ��\n");
        return 1;
                }
                else
                        return 0;
        }
        return 0;
}


int do_none()
{       
        return 1;
}

void kailiu()
{
	int i;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                if( enemy[i]->query("combat_exp")<= query("combat_exp")) {
		            set_leader(enemy[i]);
			    kill_ob(enemy[i]);
                            break;
                        }
		else
		  {
		    command("say ��������!!!����!!!");
                    set("env/wimpy", 80);
		    kill_ob(enemy[i]);	
		    random_move();
		    add("is_here",1);
		   }
                }


}

int accept_fight(object me)
{
        command("say ��С��, ��Ȼ��ͬ���������������, ����!");
        command("grin");
        kill_ob(me);
        return 1;
}

int accept_kill(object killer)
{

 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="�������") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		ob[i]->set_leader(killer);
		write(ob[i]->query("name")+ "���:"+HIY 
                "��С��, ��Ȼ��ɱ����������̵���,��ȥ����!\n" NOR);
        }
        return 1;
}



void die()
{
        object ob,*inv,dead;
	int i;
	dead=this_object();
	
message_vision("$Nҭ�����һ����,������ȥ\n������������Ŀ쵶������ͷ��������!\n",
this_object());
        ob = new(__DIR__"rentou");
	ob->set_name( dead->query("title")+"��"+dead->query("nickname")+"��"+dead->name(1)+"����ͷ", ({
"rentou" }) );
//	ob->set("victim_name", dead->name(1));
        ob->set_weight(100);
	inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++)inv[i]->move(environment());
        ob->move(environment(this_object()));
        destruct(this_object());
}

