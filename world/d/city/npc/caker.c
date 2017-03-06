// cake_vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "cake vendor", "vendor" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "һ����ò��ʵ���������壬��������Ϲ����Ͱ���Ц�ݡ�\n");
        set("combat_exp", 30);
        set("attitude", "friendly");
        set("rank_info/respect", "����");
        set("rank_info/self", "С��");
        set("vendor_goods", ([
              "���": __DIR__"obj/cake",
        ]) );
        set("chat_chance", 13);
        set("chat_msg", ({
                "��������ߺ�ȵ�������Ӵ�������ִ�Ĵ��Ӵ��\n",
                "���������ƿ�����������̽��̽�¶ȡ�\n",
                "��������ߺ�ȵ����ճ�¯�Ĵ��Ӵ���Ⱥ����Ĵ��Ӵ��\n",
        }) );
        set("inquiry", ([
                "���" : (: do_vendor_list :),
        ]) );
        setup();
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}

