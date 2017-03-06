//NPC:/d/suzhou/npc/xiaofan.c 
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

inherit F_VENDOR;

void create()
{
	set_name(MAG"小贩"NOR, ({ "xiao fan", "xiao" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这是一个普普通通的小贩。看见你在看他，对你憨厚地一笑。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ([
	"烤鸡腿":	__DIR__"obj/jitui",
	"牛皮酒袋":	__DIR__"obj/jiudai",
	]));
	setup();
}

void init()
{	
//	add_action("do_buy", "buy");
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "小贩笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "累了吧，来喝点酒，解解乏吧。\n");
			break;
	}
}

