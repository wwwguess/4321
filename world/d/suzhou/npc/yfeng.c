//NPC: /d/suzhou/npc/yfeng.c
//by dwolf
//97.11.7
     
#include <ansi.h>
inherit NPC;
inherit F_VENDOR2;

void create()
{
	set_name(HIW"迎凤"NOR, ({ "ying feng", "ying" }));
	set("title", BLK"小店老板娘"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "女性");
	set("age", 25);       
	set("per", 30);
	set("long",
		"迎凤是本mud天神之一迎风的化身，不知她这么想到到这儿来卖东\n"
		"东。真让人奇怪。\n");
	set("combat_exp", 8000);
	set("attitude", "friendly");
	set("inquiry", ([
                "迎风" : "阿风就是以前的我呀。\n",
		"迎凤" : "迎凤冷笑一声，对你的无知很不满。\n"
        ]));
		
	set("vendor_goods", ([
		"/d/quanzhou/obj/xiuhua":20,
		"/d/yueyang/obj/flower_shoe":20,
                "/d/yueyang/obj/pink_cloth":20,
                "/d/yueyang/obj/goldring":20,
                "/d/yueyang/obj/necklace":20,
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
	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("迎凤嫣然一笑，说道：姑娘来坐。\n");
		break;
	case 1 :
		say("迎凤甜腻腻地说道：可爱的女孩，你要买什么？\n");
		break;
	}
}
