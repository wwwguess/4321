// wei.c

#include <ansi.h>  

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIR"魏不悔"NOR, ({ "wei buhui", "wei" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 50);
        set("long",
        MAG"魏无双是外地人，但他人缘好，再京城很受欢迎。他已做了十几年的小买卖。\n"
"可是有些人说他会武功，整个人充满了神秘。\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 35);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
        "无情刀": __DIR__"obj/dblade.c",
        "铁盾": __DIR__"obj/shield.c",
//	"人参":"/obj/drug/sen.c",
//	"虫草":"/obj/drug/bujing_drug.c",
//	"雪莲":"/obj/drug/bushen_drug.c",
//	"灵芝":"/obj/drug/buqi_drug.c",
//	"大还丹":"/obj/drug/dahuan.c",
	"铁背心":__DIR__"obj/vest.c",
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}
