// hermit1.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����ӵ�", ({ "dumpling seller", "seller" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "��������ӵ�С������΢΢һЦ��˵���������ڵİ��ӣ���һ���ɣ�\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("vendor_goods", ([
	//	"obj/example/dumpling" : -1,
	        "����": "obj/example/dumpling",
           ]) );
	set("chat_chance", 15);
	set("chat_msg", ({
		"�����ӵ�ߺ�ȵ������ӣ������ڵİ��ӣ�\n",
	}) );
	set("inquiry", ([
		"����" : (: do_vendor_list :),
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

