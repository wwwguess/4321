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
        set("title",HIR "��"+HIB"��"+HIY "���" NOR + YEL "����" NOR +  "����");
        set("nickname", nick);

	set("age", 20);
	set("long",
		"��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 15000+random(15000));
        set("shen_type", -1);
	set("attitude", "heroism");
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(HIY "ʥ����ǧ�����أ�һͳ����!\n" NOR),
		(HIG "�ĳ���¡��󱻲���ʥ��������������!\n" NOR),
        }) );


	set_skill("unarmed", 65);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("mo-shan-jue",70);
        map_skill("dodge","mo-shan-jue");   

        create_family("�������", 16, "����");


	setup();
        
	if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/sword")->wield();
	  set_skill("sword",70);
	  set_skill("mo-jian-jue",70);
	  map_skill("sword","mo-jian-jue");
	  map_skill("parry","mo-jian-jue");   
	  
	 }	
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/blade")->wield();
	  set_skill("blade",60);
          set_skill("mo-dao-jue",60);
          map_skill("blade","mo-dao-jue");
	  map_skill("parry","mo-dao-jue");
	 }
        else if(strsrch(nick,"��")!=-1)
	 {
	  carry_object("/d/heimuya/obj/gou")->wield();
          set_skill("gou",70);
          set_skill("mo-gou-jue",70);
          map_skill("gou","mo-gou-jue");
	  map_skill("parry","mo-gou-jue");
         }
        else if(strsrch(nick,"�")!=-1)
	 {
	  carry_object("/d/heimuya/obj/ji")->wield();
          set_skill("ji",70);
          set_skill("mo-ji-jue",70);
          map_skill("ji","mo-ji-jue");
	  map_skill("parry","mo-ji-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
	 carry_object("/d/heimuya/obj/hammer")->wield();
	 set_skill("hammer",70);
         set_skill("mo-chui-jue",70);   
         map_skill("hammer","mo-chui-jue");
	 map_skill("parry","mo-chui-jue");
         }

        else if(strsrch(nick,"��")!=-1)
	 {
	  carry_object("/d/heimuya/obj/axe")->wield();
          set_skill("axe",70);
          set_skill("mo-fu-jue",70);
          map_skill("axe","mo-fu-jue");
	  map_skill("parry","mo-fu-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
         carry_object("/d/heimuya/obj/fork")->wield();
         set_skill("fork",70);
         set_skill("mo-cha-jue",70);   
         map_skill("fork","mo-cha-jue");
	 map_skill("parry","mo-cha-jue");
         }

        else if(strsrch(nick,"ǹ")!=-1)
	 {
	  carry_object("/d/heimuya/obj/qiang")->wield();
          set_skill("qiang",70);
          set_skill("mo-qiang-jue",70);
          map_skill("qian","mo-qiang-jue");
 	  map_skill("parry","mo-qiang-jue");
         }
        else if(strsrch(nick,"��")!=-1)
	 {
          carry_object("/d/heimuya/obj/whip")->wield();
	  set_skill("whip",70);
          set_skill("mo-bian-jue",70);
          map_skill("whip","mo-bian-jue");
	  map_skill("parry","mo-bian-jue");
         }
	else 
	 {
  	  set_skill("mo-zhang-jue",80);
          map_skill("unarmed","mo-zhang-jue");
	 }

        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
        add_action("do_gogo", "go");
        add_action("do_none", "north");
	add_action("do_chushi", "chushi");
	::init();
}

int do_chushi()
{
        object who,*inv;
        int i;

        who=this_player();
        if(who->query("family/family_name")=="�������")
	  {
         inv = all_inventory(who);
         for(i=0; i<sizeof(inv); i++)
         {   
         if(strsrch(inv[i]->query("name"),"����")==-1)continue;
	 message("vision",this_object()->query("name") +
                "��"+who->query("name")+"�������չ�ȥ����һ��\n",environment(who), who);

         write("�������û����,��ȥ��.\n");
	 who->move("/d/heimuya/shanjiao18.c");	 
         return 1;
         }
         write(HIR "����������Ķ�ȥ��?\n��ȥ��һ��!!\n" NOR);   
         return 1;
        }
        else
           write(HIY "��ð��?�Ŷ�û��!!!\n" NOR);
        return 1;
}

int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( (arg == "north" )&&(!query("is_here")))
        {
                if( me->query("family/family_name")!="�������") {
        command("grin");
        command("say �����ְ׵��ϵ����ﵽ�����ʲô?������!!");
        write("��������·������ס�� ��\n");
        return 1;
                }
                else
		{
		command("say ���ʾ(chushi)�������\n");
		}
                return 1;
        }
        return 0;
}


int do_none()
{       
        return 1;
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
		write(ob[i]->query("name")+ "���:"+HIY 
                "��С��, ��Ȼ��ɱ����������̵���,��ȥ����!\n" NOR);
        }
        return 1;
}



