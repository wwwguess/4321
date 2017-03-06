//NPC:/d/suzhou/npc/ren2.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"游人"NOR, ({ "you ren", "ren" }) );
	set("gender", "男性" );
	set("age", 38);
        set("long",
		"这是一位远方来的游客，满面风尘，但看上去很高兴。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "游人笑道：“终于来到苏州了。呵呵！”\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

