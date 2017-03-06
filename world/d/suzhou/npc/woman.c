//NPC:/d/suzhou/npc/woman.c 
//by dwolf   
//97.11.7

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"妇人"NOR, ({ "fu ren", "woman" }) );
	set("gender", "女性" );
	set("age", 38);
        set("long",
		"这是一位拜香的妇人，正虔诚地祈祷。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
    
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

