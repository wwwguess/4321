//NPC:/d/suzhou/npc/myren.c
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"卖艺人"NOR, ({ "mai yi ren", "ren" }));
	set("gender", "男性");
	set("age", 50);
	set("long",
        	RED"他衣着破旧，面目沧桑，看起来日子过得不怎么样。\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 300000);
        	
	set("chat_chance", 5);
	set("chat_msg", ({
		BLK"各位大爷，请多多捧场！！！"NOR,
	}) );
	
	set("force", 300);
	set("max_force", 300);
	
	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 60);
	
	setup();

	carry_object(__DIR__"obj/cloth")->wear();  
}      


