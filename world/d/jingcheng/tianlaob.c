// smith.c ����

#include <ansi.h> 

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(YEL"���ϰ�"NOR, ({ "laoban", "tian","tian laoban" }));
        set("title", "ˮ�����ϰ�");
        set("shen_type", 10000);
        set("gender", "����");
        set("age", 30);
        set("long",
      MAG"���ϰ��Ǿ�����Զ����������ʵ�ˣ�\n"
"������ˮ������û��˵������֭�࣬�˼��˰�.\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 50);

        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/xigua",
                __DIR__"obj/yangmei",
                __DIR__"obj/dazao",
	        __DIR__"obj/caomei",
                __DIR__"obj/miju",
                __DIR__"obj/xiangjiao",

        }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "mai");
}

