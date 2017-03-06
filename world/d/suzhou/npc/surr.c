//NPC:/d/suzhou/npc/surr.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"穆念慈"NOR, ({ "mu nianci", "mu"}) );
	set("gender", "女性" );
	set("age", 38);
        set("long",
		"她就是穆念慈，她正微笑着和同伴聊天，偶尔想起杨过，不由黯然失色。\n");
	set("combat_exp", 20000);
	set("int",70);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "穆念慈对同伴说道：“我的过儿到哪儿去了呢?”\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

