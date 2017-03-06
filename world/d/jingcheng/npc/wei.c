// wei.c

#include <ansi.h>  

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIR"κ����"NOR, ({ "wei buhui", "wei" }));
        set("title", "�ӻ����ϰ�");
        set("shen_type", 1);

        set("gender", "����");
        set("age", 50);
        set("long",
        MAG"κ��˫������ˣ�������Ե�ã��پ��Ǻ��ܻ�ӭ����������ʮ�����С������\n"
"������Щ��˵�����书�������˳��������ء�\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 35);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
        "���鵶": __DIR__"obj/dblade.c",
        "����": __DIR__"obj/shield.c",
//	"�˲�":"/obj/drug/sen.c",
//	"���":"/obj/drug/bujing_drug.c",
//	"ѩ��":"/obj/drug/bushen_drug.c",
//	"��֥":"/obj/drug/buqi_drug.c",
//	"�󻹵�":"/obj/drug/dahuan.c",
	"������":__DIR__"obj/vest.c",
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}
