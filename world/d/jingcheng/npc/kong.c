// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("孔长生", ({ "kong changsheng" , "kong" , "changsheng" }));
	set("title",GRN"木器店老板"NOR);
	set("long",
	"孔记木器店的老板，他有一双天下无双的巧手，做出来的木器真是神乎其技。在京城\n"
	"也算小有名气的人物，无数人慕名而来仅仅是为了求他做件竹椅。\n");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 20);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 10);
        set("vendor_goods", ([
         "红木鼎" : __DIR__"obj/muding",
         "木椅" :  __DIR__"obj/muyi",
           ]));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"孔长生轻轻一笑说：多谢大家捧场。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
         add_action("do_vendor_list","list");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"四处看看，对什么东西有兴趣。\n");
}

