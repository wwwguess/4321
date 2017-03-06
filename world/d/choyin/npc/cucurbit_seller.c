// cucurbit_seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("���Ǻ�«��", ({ "cucurbit chapman", "chapman" }) );
	set("gender", "����" );
	set("age", 42);
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	      "�Ǻ�«":__DIR__"obj/cucurbit",
	]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"���Ǻ�«��ߺ�ȵ����Ǻ�«�����������Ǻ�«��\n",
	}) );
	set("inquiry", ([
		"�Ǻ�«" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

