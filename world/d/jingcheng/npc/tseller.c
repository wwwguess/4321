// tseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"糖人王"NOR, ({ "tangren wang", "wang" }));
	set("title", YEL"卖糖人"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "男性");
	set("age", 20);
	set("long", "别看糖人王年纪不大，做的糖人可好了，那可是他家传的手艺\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
               "孙悟空糖人": __DIR__"obj/tren1.c",
               "猪八戒糖人": __DIR__"obj/tren2.c",    
		"沙僧糖人":__DIR__"obj/tren3.c",
	"唐僧糖人":	__DIR__"obj/tren4.c",
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"快来吃糖人喔！\n"NOR, 
		YEL"价格便宜，大家都来吃啊！呵呵！！\n"NOR,
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

