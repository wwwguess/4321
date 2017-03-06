// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����ӵ�", ({ "seller" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��������ӵ�С������΢΢һЦ��˵���������ڵİ��ӣ���һ����\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
        set("chat_msg", ({
                       "�����ӵ�ߺ�ȵ������ӣ������ڵİ��ӣ�\n",
        }) );
                               
	set("vendor_goods", ([
		"����": "/obj/example/dumpling",
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
//		remove_call_out("greeting");
//		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}
