//NPC:/d/suzhou/npc/ren3.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"行人"NOR, ({ "xing ren", "ren" }) );
	set("gender", "男性" );
	set("age", 58);
        set("long",
		"这是一位本地的公民，看上去很悠闲。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "行人笑道：“欢迎来苏州玩。呵呵！”\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

