// boss.c

inherit NPC;

void create()
{
	set_name("���ƹ�", ({ "boss tang", "tang", "boss" }) );
	set("long",
		"���ƹ�����Ҵ��¥�����ˣ�����ֻ��һ��СС�ľ�¥�ϰ壬����\n"
		"�ؾ��ڳ���֪����ү���⣬���¾�������ƴ��ƴ�\n" );
	set("age", 46);
	set("attitude", "peaceful");
	set("combat_exp", 1000);
	set("inquiry", ([
		"name": "������������һ��ҵ�֡�\n",
		"here": "�˴����Ǹ��־�¥��������Ҫ��ˣ��Ը������С��һ����ɡ�\n",
		"��ҵ": "���ң����±�����ҵ����֪�����кηԸ���\n",
		"���־�¥": "������ǣ������ǵ�һ������\n"
	]) );
	setup();
	add_money("silver", 15);
	carry_object("/obj/cloth")->wear();
}

