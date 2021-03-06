// lin.c 林老板
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIR"林老板"NOR, ({ "lin laoban", "lin" }));
	set("title", HIB"古董店老板"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "男性");
	set("age", 40);
	set("long", "林老板经营祖传下来的古董店已有多年。\n");
	set("combat_exp", 50000);
        set("kee", 300);
        set("max_kee", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ([
               "翡翠杯": __DIR__"obj/cup.c",
               "和氏璧": __DIR__"obj/hsbi.c",    
	"先秦陶马":	__DIR__"obj/horse.c",
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                "请随便看看，看有没有中意的东西。\n", 
		"本店的古董都是货真价实的宝贝。不要错过喔。\n",
        }) );

	add_money("gold", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

