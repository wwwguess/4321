// fengbuping.c -�ⲻƽ
#include <ansi.h>
inherit NPC;
int ask_xueyi();

void create()
{
        set_name("�ⲻƽ",({"feng buping","buping","feng"}));
        set("long",
                "��ɽ�ɽ��ڴ��ˡ�\n"
                "���ǻ�ɽ���ڵĵ�һ���֡�����֮������һ��Ϳ�أ��ⲻƽ���ӿ�������\n");
	set("title", GRN "��ɽ" NOR + YEL "����" NOR + CYN "����" NOR);
        set("gender", "����");
        set("age", 40);
	set("feilong", 1);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_kee",  2000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 1000000);
        set("score", 10000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feilong" :),
        }) );

        set_skill("force", 130);
        set_skill("huashan-neigong", 140);
        set_skill("dodge", 150);
        set_skill("huashan-shenfa", 150);
        set_skill("parry", 150);
        set_skill("sword", 160);
        set_skill("huashan-jianfa", 160);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��" , 18, "����");
        set("inquiry", ([
                "ѧ��" : (: ask_xueyi :),
        ]) );

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
int ask_xueyi()
{ 
	mapping myfam;
        if (!(myfam = this_player()->query("family"))
            	|| myfam["family_name"] != "��ɽ��")
   	{
   		say("�ⲻƽ˵����Ǳ��ɵ��ӣ��˻�̸��˵��\n");
             	return 1;
   	}
  	else
  	{
  		say("�ⲻƽ˵���������Ѳ���ͽ���������ܸ�����ϼ�ؼ����ҿ��Խ���һ�С�\n");
  	    	this_player()->set_temp("marks/ѧ��", 1);
  	  	return 1;
  	}
}
int accept_object(object ob, object obj)
{
        object me = this_player();
	mapping myfam;

        if(obj->query("id") == "zixia miji") 
        {
        	if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "��ɽ��" )
		{      	command("say �ã���Ȼ���������ϼ�ؼ����Ҿͽ���һ�С������������");
			if (me->query_skill("huashan-jianfa", 1) >=100)
			{
				say("�����˷ⲻƽ�Ľ��⣬ѧ������һ�С�\n");
				me->set("feilong",1);
                		return 1;
			}
			else
			{
				say("������Ļ�ɽ�����ȼ��������Էⲻƽ�Ľ���û��������\n");
				return 1;
			}
		}
		else 
		{	command("say �ҿ�û��������ѽ");
                	return 1;
        	}
	}
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

