//girl.c 
// created by kiss
inherit NPC;
#include <ansi.h>
inherit F_VENDOR;

void create()
{
	set_name(YEL"卖花小女孩"NOR, ({ "girl"}) );
	set("gender", "女性" );
	set("age", 13);
        set("long",
		"这是一位卖花的小女孩，正向你微笑着。\n");
	set("combat_exp", 20);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",5);
        set("chat_msg", ({
                "小女孩对你说道：“你买几朵花吧。”\n",
                "小女孩看着你，笑道：“看你这傻样，你好笨呀！”\n",
                (: random_move :)
        }) );
	set("vendor_goods", ([
	"白兰花":	__DIR__"obj/bailan_flower",
	"红玫瑰":	__DIR__"obj/red_flower",
	]));
	setup();
	add_money("silver",5);
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
			say( "小女孩快活地说道：这位" + RANK_D->query_respect(ob)
				+ "，买两朵花给心上人吧。\n");
			break;
		case 1:
			say( "小女孩说道：这位" + RANK_D->query_respect(ob)
				+ "，公子就买白兰花，小姐就买头戴红花。\n");
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
