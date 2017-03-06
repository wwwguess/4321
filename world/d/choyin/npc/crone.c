// crone.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("Ǭ����̫��", ({ "crone" }) );
	set("gender", "Ů��" );
	set("age", 73);
	set("long",
		"�����̫�Ż��б��˸���¨���ƺ�����ʲô������Ҳ��\����Ը�������\n"
		"��Ǯ��\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"����": "���������ʮ�а�����\n",
		"here":	"��һ���ҿ����ˡ�\n",
		"���ǲ�": "��������ԼԼ����˵��ʲô���ݡ�������ʨ�ӡ��ģ������Ҳ�Ͳ�֪�ˡ�\n",
		]) );

	set("vendor_goods", ([
		"ƽ����": "/d/choyin/npc/obj/amulet",
		"����": "/d/choyin/npc/obj/red_guay",
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

void relay_ask(object me, string topic)
{
	command("?");
	command("say �Բ��������Ӷ�����" + RANK_D->query_respect(me) + "������"
		"�����ɣ�����м�Ǯ(list) ....\n");
	message("vision", "��̫�Ŵ���¨����\����������ֽƬ��\n", environment(me));
}
