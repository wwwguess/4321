// smith.c ����

#include <ansi.h> 

inherit NPC;
inherit F_VENDOR;

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
        set("vendor_goods", ([
               "����": __DIR__"obj/xi",
               "��÷": __DIR__"obj/yang",
               "����": __DIR__"obj/dazao",
	       "��ݮ": __DIR__"obj/cao",
                "�۽�":__DIR__"obj/miju",
                "�㽶":__DIR__"obj/xiangjiao",

        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
//        add_action("do_buy", "buy");
}

