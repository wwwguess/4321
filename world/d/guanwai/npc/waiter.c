// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("班察那", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set_skill("iron-cloth", 2000);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 50);
	map_skill("unarmed", "bloodystrike");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"破剑": __DIR__"obj/junksword",
		"破刀": __DIR__"obj/junkblade",
		"木禅杖": __DIR__"obj/junkstaff",
		"玉戒指": __DIR__"obj/jade3",
		"布袋": "/obj/example/bag",
		"羊皮酒袋": __DIR__"obj/wineskin",
		"烤羊腿": __DIR__"obj/sheep_leg",
		"一份蛇药": __DIR__"obj/snake_drug",
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店小二班察那笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二班察那用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二班察那说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}
