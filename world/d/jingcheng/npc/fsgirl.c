// fsgirl.c  卖花女孩
// phoebus.1997  
//changed by dwolf

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(RED"女孩"NOR, ({ "sell flower girl", "girl" }) );
	set("gender", "女性" );
	set("age", 18);
	set("title", YEL"我是"NOR RED"卖花的"NOR HIM"女孩"NOR);
	set("long",
		MAG"这是一位卖花的女孩，挺可爱的样子，正向你微笑着。\n"NOR);
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	 set("pursuer", 1);
	set("chat_chance",5);
        set("chat_msg", ({
                YEL"女孩对你说道：“你买几朵花吧。”\n"NOR,
                YEL"女孩看着你，吃吃笑道：“看你这傻样，你好笨呀！”\n"NOR,
        }) );
	set("vendor_goods", ([
	"水仙花":	__DIR__"obj/sxh.c",
	"牡丹花":	__DIR__"obj/mdan.c",
	"玫瑰花":	__DIR__"obj/mgui.c",
	]));
	setup();
	add_money("silver",3);
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);

	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say(YEL "女孩快活地说道：这位" + RANK_D->query_respect(ob)
				+ "，买两朵花给心上人吧。\n"NOR);
			break;
		case 1:
			say( YEL"女孩说道：这位" + RANK_D->query_respect(ob)
				+ "，公子就买玫瑰花，小姐就买头戴水仙花。\n"NOR);
			break;
	}
}

int accept_fight(object me)
{
	command("say 你发什么病？干吗要打我？");
	command("chat 各位，我这的这位" + RANK_D->query_respect(me) + "要打我，谁来救我呀！"); 
	command("cry");
	kill_ob(me);
	return 1;        
}
