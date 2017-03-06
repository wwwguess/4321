//NPC:/d/suzhou/npc/ren.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"游人"NOR, ({ "you ren", "ren" }) );
	set("gender", "男性" );
	set("age", 28);
        set("long",
		"这是一位远方的游客，满面风尘，但看上去很高兴。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "游人");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "游人笑道：“终于到了！”\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

