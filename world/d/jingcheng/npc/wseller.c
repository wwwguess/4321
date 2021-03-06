// wseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"朱阿香"NOR, ({ "zhu axiang", "zhu" }));
	set("title", YEL"卖玩具人"NOR); 
	set("shen_type", 1);

	set("str", 18);
	set("gender", "女性");
	set("age", 18);
	set("long", "阿香是个挺漂亮的姑娘，她是牛二的邻居，两人非常要好。\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
              "青葫芦":  __DIR__"obj/wanju1.c",
                "面具":__DIR__"obj/wanju2.c",    
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                MAG"啊！是牛家二哥。好啊！\n"NOR, 
		MAG"买玩具呀！买玩具呀！！\n"NOR,      
		(: random_move :)
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

