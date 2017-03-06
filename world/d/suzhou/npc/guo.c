//NPC:/d/suzhou/npc/guo.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;           
void create()
{
	set_name(HIM"郭啸天"NOR, ({ "guo xiaotian", "guo"}) );
	set("gender", "男性" );
	set("age", 68);
        set("long",
		"这是一位威严的老人，穿得不错，不知道为什么在这儿练拳。\n");
	
	set("per", 30);
	set("int", 30);  
	set("str", 40);

	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("rank_info/respect", "英雄");
	set("pursuer", 1);      
	set_skill("iron-cloth", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("chat_chance",2);
        set("chat_msg", ({
                YEL"郭啸天猛然挥出一拳，把身后的墙打了一个大洞。\n"NOR,
                RED"然后郭啸天又是一记扫堂腿，把一根栓马的柱子连根踢倒。\n"NOR,
               
        }) );
	
	setup();
	add_money("silver",0);   
	carry_object(__DIR__"obj/cloth2.c")->wear();
}

