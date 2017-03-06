// wei.c  

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("κ��˫", ({ "Yang yongfu", "yang" }));
        set("title", "�ӻ����ϰ�");
        set("shen_type", 1);

        set("gender", "����");
        set("age", 50);
        set("long",
                "κ��˫������ˣ�������Ե�ã��پ��Ǻ��ܻ�ӭ����������ʮ�����С������\n
������Щ��˵�����书�������˳��������ء�");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 35);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/dblade.c",
                __DIR__"obj/pbook.c",
        }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
