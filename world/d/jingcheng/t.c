// smith.c 铁匠

#include <ansi.h> 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(YEL"田老板"NOR, ({ "laoban", "tian","tian laoban" }));
        set("title", "水果店老板");
        set("shen_type", 10000);
        set("gender", "男性");
        set("age", 30);
        set("long",
      MAG"田老板是京城里远近闻名的老实人，\n"
"他卖的水果真是没的说，个大汁多，人见人爱.\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 50);

        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([
               "西瓜": __DIR__"obj/xi",
               "杨梅": __DIR__"obj/yang",
               "大枣": __DIR__"obj/dazao",
	       "草莓": __DIR__"obj/cao",
                "蜜桔":__DIR__"obj/miju",
                "香蕉":__DIR__"obj/xiangjiao",

        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
//        add_action("do_buy", "buy");
}

