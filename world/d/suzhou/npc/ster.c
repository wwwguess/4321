//NPC:/d/suzhou/npc/ster.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"甜儿"NOR, ({ "tian er" }) );
	set("gender", "女性" );
	set("age", 18);
        set("long",
		"她就是一个可爱的女孩，她正微笑着和同伴说笑。\n");
	set("combat_exp", 20000);
	set("int",40);
	set("per",40);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "甜儿笑道：“嘻嘻....”\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

