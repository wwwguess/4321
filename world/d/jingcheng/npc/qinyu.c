// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("秦玉", ({ "qin yu", "qin" ,"yu" }));
	set("title",GRN"将军府总管"NOR);
	set("long",
	"秦玉是将军府的老人，他自小在将军府长大，深得秦将军的信任，把总管的\n"
	"大权交给他。\n");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 80000);
	set_skill("dodge",70);
	set_skill("unarmed", 60);
	set_skill("sword", 80);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"秦玉看着你说：“如今天下太平，歌舞升平，需要好好整治军备。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	add_action("do_answer", "answer");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
		if( me->query_temp("baishi") )
			me->delete_temp("baishi");
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	if( random(10) >5 
	&& (me->query("title") == "平民" || me->query("title") == "民女" ))
	{
		command("say "+RANK_D->query_respect(me)+"现在正是为国效力的时候。\n"
		+RANK_D->query_respect(me)+"何不加入我将军府。\n");
		command("smile");
	}
}

int do_answer(string arg)
{
	object ob;
	
	ob = this_player();

	if( !arg ) return notify_fail("你要回答什么？\n");
	if( strsrch(arg,"拜师") != -1 ){
		ob->set_temp("baishi", 1);
		message_vision("$N高兴的说：我将军府地位显赫，武艺高强，在江湖上也是大大的\n"
		"有名,"+ob->query("name")+"可算是找对地方了.\n", this_object());
		return 1;
	} else {
		message_vision("$N很不高兴的看着$n，冷冷的说：本府可不让你这种无聊之人进去。\n"
		, this_object(), ob);
		ob->move("/d/jingcheng/xw7");
		return 1;
	}
}
