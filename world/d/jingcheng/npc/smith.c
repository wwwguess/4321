// smith.c ����

#include <ansi.h> 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(YEL"������"NOR, ({ "tiejiang wang", "wang" }));
        set("title", "�������ϰ�");
        set("shen_type", 10000);

        set("gender", "����");
        set("age", 80);
        set("long",
                MAG"�������Դ���Ϊ����������ı����������������ݵ���������������һ����\n"
"������С���ӡ�����������Ϊ���ȵ����ŷұ�Ӹ�ţ��\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 50);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "ԧ�쵶":__DIR__"obj/yblade",
                "��ͭ����":__DIR__"obj/staff",
                "��������":__DIR__"obj/kaijia",
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}

