//vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����׳��", ({ "vendor man","man" }) );
        set("gender", "����" );
        set("age", 34);
        set("long", "һ�����������׳������ˮ�Ľ�����˵��ʲô��\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "��ҩ": "/obj/drug/hurt_drug",
        ]) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "����׳��ߺ�ȵ������⿿���ѣ���λ������Ǯ����\n",
                "����׳������һ��������������ģ������\n",
                "����׳����������˵�������¸�·�����ᣡ\n",
        }) );
        set("inquiry", ([
                "��ҩ" : (: do_vendor_list :),
        ]) );
        setup();
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}

