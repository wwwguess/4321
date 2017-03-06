// smith.c ���� 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "tiejiang li", "li" }));
        set("title", "�������ϰ�");
        set("shen_type", 0);

        set("gender", "����");
        set("age", 60);
        set("long",
                "�������Դ���Ϊ����������ı���Զ��������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 55);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
               "/obj/weapon/duanjian":5,
               "/obj/weapon/changjian":4,
               "/obj/weapon/gangjian":3,
               "/obj/weapon/gangdao":5,
               "/obj/weapon/tiegun":6,
               "/obj/weapon/bian":2,
               "/obj/weapon/hammer":3
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("do_buy", "buy");
}

