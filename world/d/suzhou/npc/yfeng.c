//NPC: /d/suzhou/npc/yfeng.c
//by dwolf
//97.11.7
     
#include <ansi.h>
inherit NPC;
inherit F_VENDOR2;

void create()
{
	set_name(HIW"ӭ��"NOR, ({ "ying feng", "ying" }));
	set("title", BLK"С���ϰ���"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "Ů��");
	set("age", 25);       
	set("per", 30);
	set("long",
		"ӭ���Ǳ�mud����֮һӭ��Ļ�����֪����ô�뵽�����������\n"
		"������������֡�\n");
	set("combat_exp", 8000);
	set("attitude", "friendly");
	set("inquiry", ([
                "ӭ��" : "���������ǰ����ѽ��\n",
		"ӭ��" : "ӭ����Цһ�����������֪�ܲ�����\n"
        ]));
		
	set("vendor_goods", ([
		"/d/quanzhou/obj/xiuhua":20,
		"/d/yueyang/obj/flower_shoe":20,
                "/d/yueyang/obj/pink_cloth":20,
                "/d/yueyang/obj/goldring":20,
                "/d/yueyang/obj/necklace":20,
	]));           

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_vendor_list", "list");
	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("ӭ����ȻһЦ��˵��������������\n");
		break;
	case 1 :
		say("ӭ���������˵�����ɰ���Ů������Ҫ��ʲô��\n");
		break;
	}
}
