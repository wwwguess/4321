// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "seller" }) );
        set("title", "����ϰ�");
        set("gender", "����" );
        set("age", 32);
        set("long", "���ϰ峤�úܰ׾���һ�������˵���ʵ�ࡣ\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 70);
        set_skill("dodge", 50);

        set("inquiry", ([
                "���" : "Ϊ�����˰����Ҳ�Ǿ�һ�����⡣", 
        ]) );

        set("vendor_goods", ([
		"�ε���ѡ":"/obj/book",
                "���":"/obj/book1",
                "̫����":"/obj/book2",
                "�����ļ�":"/obj/book3",
                "˵��":"/obj/book4",
                "����־":"/obj/book5",
                "����":"/obj/book6",
                "٫��իʫ��":"/obj/book7",
                "��ʿ�д�":"/obj/book8",
                "ˮ��ͼע":"/obj/book9",
        	"˵�Ľ���": "/u/cloud/obj/literate_book",	
	]) );

        setup();
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
                        say( "������ӭ������˵����"
                                + RANK_D->query_respect(ob)
                                + "����������ģ�\n");
                        break;
                case 1:
                        say( "���������ĵ�̾�˿�����˵�����������������Ѱ�������\n");
                        break;

		case 2:
			say( "��������۾�����ؿ����飬�ƺ�ûע����ĵ�����\n");
			break;

        }
}

