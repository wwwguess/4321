// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("葛六", ({ "ge liu", "ge", "liu" }) );
        set("title",YEL "店小二" NOR);
        set("nickname", GRN "京城一绝" NOR);
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
        set("vendor_goods", ([
                "蟹黄包子":__DIR__"obj/xhbaozi",
                "水晶包子":__DIR__"obj/shjbaozi",
                "红烧豆腐":__DIR__"obj/hshdoufu",
                "麻辣豆腐":__DIR__"obj/mldoufu",
                "砂锅饭":__DIR__"obj/shgfan",
                "排骨面":__DIR__"obj/pgmian",
                "酸辣汤":__DIR__"obj/sltang",
                "糖醋鲤鱼":__DIR__"obj/tcliyu",
                "花生米":__DIR__"obj/hshmi",
           ]));
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
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
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break; 
                case 2:
			say( "店小二点头哈腰，往楼上一指说道：这位" + RANK_D->query_respect(ob)
				+ "，楼上雅座请。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
    if(ob->query("money_id") && ob->value() >=500)
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，您慢慢用。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
