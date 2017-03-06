//NPC:/d/suzhou/npc/lhxiu.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(RED"李师师"NOR, ({ "li shishi", "li"}) );
	set("gender", "女性" );
	set("age", 28);
        set("long",
		"她是一个可爱的女孩，是当代最有名的歌妓，她正微笑着和同伴说笑。\n");
	set("combat_exp", 20000);
	set("int",40);
	set("per",40);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "李师师笑道：“嘻嘻，你这小调皮鬼。”\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

