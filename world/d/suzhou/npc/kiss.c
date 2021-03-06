//NPC: /d/suzhou/npc/kiss.c
//by dwolf
//97.11.7
         
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(RED"点点"NOR, ({ "dian dian", "kiss" }));
	set("title", YEL"茶馆老板娘"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "女性");
	set("age", 22);
	set("long",  "点点是大仙啦，不知道怎么开上茶馆了。 \n");

	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("inquiry", ([
		"点点" : "点点就是我啦。\n",
		"生意" : "这个么……，就靠您多关照了，嘻嘻。\n",
	]));
	
	set("vendor_goods", ([
		"/d/suzhou/npc/obj/peanut",
		"/d/suzhou/npc/obj/tofu",
	]));

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_vendor_list", "list");
//        add_action("do_buy", "buy");
//	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("点点笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来喝杯热茶。\n");
		break;
	case 1 :
		say("点点说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店有刚炸好的五香花生出售。\n");
		break;
	}
}
