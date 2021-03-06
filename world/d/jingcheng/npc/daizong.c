// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("戴宗", ({ "dai zhong", "dai" ,"zhong" }));
	set("title",GRN"驿站站长"NOR);
	set("nickname", RED"神行太保"NOR);
	set("long",
	"神行太保据说是江湖上跑得最快的人。他可以日行一千，夜行八百。江湖上\n"
	"有了什么新鲜事，他总是第一个知道的。\n");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 20);
	set("combat_exp", 50000);
	set_skill("dodge",70);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"戴宗看着你说：“人腿毕竟是血肉做的，有时候也该换换脚力，对吧。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	message_vision("戴宗对着$N微微一笑。\n",me);
}
