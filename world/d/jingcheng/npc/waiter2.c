// waiter2.c 
//by dwolf  

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(YEL"店小二"NOR, ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
                "酒": "/obj/example/wineskin",
                "包子": "/obj/example/dumpling",
                "鸡腿": "/obj/example/chicken_leg",  
	]));
	setup();
}

void init()
{	
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来吃点东西，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/yueyang/beidajie2");
	message("vision","只听“乒”地一声，" +  ob->query("name") +
		"被人从醉仙楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
