// girl.c

inherit NPC;

string ask_youngman();

void create()
{
	set_name("�ټ�С��", ({ "girl" }) );
	set("long", "һ��������������Ǯ�˼ҵ�Ů�ӣ����������κ���\n");
	set("age", 23);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"name": "�� ... �� ��������˶�������ô��İ������Ĺ�����",
		"here": "���ﰡ��������������������Ĵ���������",
		"����": "����û����ò�ļһ�ҲŲ������㣡",
		"�ν�" : (: ask_youngman :), 
	]) );
	setup();
	carry_object(__DIR__"obj/lady_dress")->wear();
	carry_object(__DIR__"obj/silver_clasp")->wear();
}

string ask_youngman()
{
	object bag, me;

//	if( !me = query_temp("last_asker") ) return "��˵���� ... �������δ��˸��ϵ��� ... ���๫��\n";

	bag = new(__DIR__"obj/silk_bag");
	bag->move(this_player());
        return "СŮ����һ������ ... ��������������� ... �ι��ӡ�\n";
        delete("inquiry/�ν�");
}

