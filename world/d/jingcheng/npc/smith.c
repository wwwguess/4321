// smith.c 铁匠

#include <ansi.h> 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(YEL"王铁匠"NOR, ({ "tiejiang wang", "wang" }));
        set("title", "铁匠铺老板");
        set("shen_type", 10000);

        set("gender", "男性");
        set("age", 80);
        set("long",
                MAG"王铁匠以打铁为生，他打造的兵器天下闻名。扬州的李铁匠不过是他一个不\n"
"成器的小弟子。有人甚至认为他比当年的欧冶子更牛。\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 50);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "鸳鸯刀":__DIR__"obj/yblade",
                "黄铜禅杖":__DIR__"obj/staff",
                "金轮铠甲":__DIR__"obj/kaijia",
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}

