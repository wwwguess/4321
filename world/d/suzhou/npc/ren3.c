//NPC:/d/suzhou/npc/ren3.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"����"NOR, ({ "xing ren", "ren" }) );
	set("gender", "����" );
	set("age", 58);
        set("long",
		"����һλ���صĹ��񣬿���ȥ�����С�\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "����Ц��������ӭ�������档�Ǻǣ���\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

