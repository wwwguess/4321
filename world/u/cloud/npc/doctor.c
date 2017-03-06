// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���", ({ "waiter" }) );
        set("title", "ҩ��");
        set("gender", "����" );
        set("age", 17);
        set("long", "ҩ���С��ƣ�����ѧ����ҩ��\n");
        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        set("inquiry", ([
		"ץҩ" : "�����Ǹ�����õ�ҩ�꣬��Ҫʲô��",
        ]) );

        set("vendor_goods", ([
                "��ҩ": "/obj/drug/hurt_drug",
		"��ҩ": "/obj/drug/snake_drug",
	//	"�˲�": "/u/cloud/obj/meat/tail",
	//	"������": "/u/cloud/obj/meat/zasui",
        ]) );

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "С��Ƴ��˼�ζҩ��������ֽ����\n");
                        break;
                case 1:
                        say( "��Ƶ�ͷ������λ"  
				+ RANK_D->query_respect(ob)
                                + "����ҩ��\n");
                        break;
        }
}

