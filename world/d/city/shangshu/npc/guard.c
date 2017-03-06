// guard.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ŷ�", ({ "guard" }) );
        set("id", "guard");
	set("long",
		"���鸮���ŷ���Ȼûʲô���Σ������������\n"
		"����İ����޲������Ϲ��Ͼ��ġ\n"
		);

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 1000);

        set("chat_chance", 5);
	set("chat_msg", ({
        	"�ŷ������̵�˵���ǡ������������˵��𣿡���\n",
		"�ŷ��ٺٵ�Ц��Ц������Ȼ���һ������.\n"
		}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if ( !who->query("marks/����") ) {
                if( ob->value() >=30000 ) {
                        say("�ŷ�˵��:��λ���ˣ������룡\n"); 
                        who->set("marks/����",1);
                        return 1;
			}  
	           else {
       		         say ("���������һ����ͷ���˹�ȥ��\n"); 
			 return 1;
       			 }
		}

	else {
		say ("����̫������\n");
        	return 1;
		}
}

