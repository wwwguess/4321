//NPC:/d/suzhou/npc/ren.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"����"NOR, ({ "you ren", "ren" }) );
	set("gender", "����" );
	set("age", 28);
        set("long",
		"����һλԶ�����οͣ�����糾��������ȥ�ܸ��ˡ�\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "����");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "����Ц���������ڵ��ˣ���\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

