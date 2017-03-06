//NPC: /d/suzhou/npc/kiss.c
//by dwolf
//97.11.7
         
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(RED"���"NOR, ({ "dian dian", "kiss" }));
	set("title", YEL"����ϰ���"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "Ů��");
	set("age", 22);
	set("long",  "����Ǵ���������֪����ô���ϲ���ˡ� \n");

	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("inquiry", ([
		"���" : "������������\n",
		"����" : "���ô�������Ϳ���������ˣ�������\n",
	]));
	
	set("vendor_goods", ([
		"/d/suzhou/npc/obj/peanut",
		"/d/suzhou/npc/obj/tofu",
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
//        add_action("do_buy", "buy");
//	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("���Ц���е�˵������λ" + RANK_D->query_respect(ob) +
			"����������ȱ��Ȳ衣\n");
		break;
	case 1 :
		say("���˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
			"�����˰��������и�ը�õ����㻨�����ۡ�\n");
		break;
	}
}
