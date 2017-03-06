// guard.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"�ŷ�"NOR, ({ "men fang", "guard" }) );
      	set("long", "����ŷ���Ȼ�书���ߣ������н�����ѩɽׯ�����޲������Ϲ��Ͼ��ġ� \n"); 

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 5000);

        set("chat_chance", 5);
	set("chat_msg", ({
        	"�ŷ������̵�˵���ǡ���������Ǵ�ѩɽׯ�𣿡���\n",
	        "����ɽׯ�ķ�̫�������ȥ���ǲ��ǣ��������ٺ�.\n",
		}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
        carry_object("/d/suzhou/npc/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if ( !who->query("marks/��ѩɽׯ") ) {
                if( ob->value() >=10000 ) {
                        say("�ŷ�˵��:�����룡\n"); 
                        who->set("marks/��ѩɽׯ",1);
                        return 1;
		}  
	        else {
       		         say ("���������һ����ͷ���˹�ȥ��\n"); 
			 return 1;
       		     }
		}

	else {
		say ("��̫������\n");
        	return 1;
		}
}

      