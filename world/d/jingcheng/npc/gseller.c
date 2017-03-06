// gseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"牛二"NOR, ({ "niu er","seller" }));
	set("title", RED"卖糕点人"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "男性");
	set("age", 18);
	set("long", "牛二这人心眼好，又风趣幽默，很讨人喜欢。\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
               "雪花糕点": __DIR__"obj/gaodian1.c",
               "香糕": __DIR__"obj/gaodian2.c",    
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"买糕点喔，快来买糕点喔，现炒现卖啊！\n"NOR, 
		YEL"朱家妹子，你也来了。散集时咱们一起回家吧！\n"NOR,   
	(: random :)
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

