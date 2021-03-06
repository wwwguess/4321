//NPC:/d/suzhou/npc/xiaoer2.c 
//by dwolf
//97.117

#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
        "女儿红": __DIR__"obj/nuerh",
        "竹叶青":         __DIR__"obj/zhuyeq",
        ]));

	setup();
}

void init()
{	
        object ob; 
//        mapping myfam; 

        ob = this_player();
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来住一宿，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break; 
                case 2:
			say( "店小二点头哈腰，往后面一指说道：这位" + RANK_D->query_respect(ob)
				+ "，后院有雅房，请。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
    if(ob->query("money_id") && ob->value() >=500)
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，您请进。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
