// smith.c

inherit NPC;

void create()
{
	set_name("������", ({ "wang", "smith" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "������������ǯ��סһ����ȵ�����Ž�¯�С�\n");
	set("combat_exp", 400);
	set("inquiry", ([
		"name": "С������������һ�����֣�����С�����ϴ����ʶ����һ����ֻ�����ֻ�д��\n",
		"here": "������С�˺��ڵ����ӣ�С��һ����ڶ�ס�ں�ߵ����ӡ�\n",
		"��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...\n",
		"����": "�Բ���С�˵���Ĳ��Ӷ����˶����ˡ�\n",
		"����": "������С������������������ã�һ��ֻҪ������Ǯ��\n"
	]) );
	setup();
	carry_object(__DIR__"obj/hammer")->wield();
}

int buy_object(object who, string what)
{
	if( what=="����" ) return 300;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	ob = new(__DIR__"obj/hammer");
	ob->move(who);
	message_vision("$N����$nһ������Ĵ�����������\n", this_object(), who);
}
