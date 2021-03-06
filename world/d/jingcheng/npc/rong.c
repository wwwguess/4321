// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("荣有禄", ({ "rong youlu", "rong" , "youlu" }));
	set("title",RED"肉铺老板"NOR);
	set("long",
	"荣记肉铺的老板，长得虎背熊腰。他曾经随大军西征，学了一点武功，但为人老实，\n"
	"自打这肉铺开门以来，还从没发生过短斤少两的事，所以生意愈见红火起来。\n");
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	 set("vendor_goods", ([
           "羊肉":__DIR__"obj/yangrou",
           "猪头肉":__DIR__"obj/zhutou",
           "牛尾":__DIR__"obj/niuwei",
           "马肉":__DIR__"obj/marou",
           "驴肉":__DIR__"obj/lvrou",
           "牛肉":__DIR__"obj/niurou",
            ]));
   
	set("str", 25);
	set("int", 5);
	set("con", 25);
	set("kar", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"荣有禄看了你一眼，满面堆笑道：客人这边请了。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/shzhdao")->wield();
}
void init()
{
	object me;
    	::init();
	add_action("do_vendor_list", "list");
 
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	if( (string)me->query("family/family_name") == "武当派" 
	|| (string)me->query("family/family_name") == "少林派" )
	{
		command("? "+me->query("id"));
		command("say 出家人首戒杀生、吃荤，"+RANK_D->query_respect(me)+
		"怎么跑到这儿来了。不妥！不妥！\n");
		command("shake "+me->query("id"));
		command("say "+RANK_D->query_respect(me)+"还是请回吧。本店对出家人恕不奉陪。\n");
		tell_room(environment(me),(string)me->query("name")+
	"被容有禄给半推半拖的从肉铺里轰了出去.\n",({me, this_object()}));
		me->move("/d/jingcheng/baih4");
		return;
	}
	command("say "+RANK_D->query_respect(me)+"买肉啊。\n");
}
