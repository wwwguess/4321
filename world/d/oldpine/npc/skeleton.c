// phantomforce.c

inherit ITEM;

void create()
{
//	seteuid(geteuid());

	set_name("һ���Ѿ�����ĺ���", ({ "skeleton" }));
	set_weight(3500);
	set("unit", "��");
	set("long",
		"һ���Ѿ�����ĺ��Ǿ����ز�֪���˶�á�\n"
	);
	set("no_get", "���ܶ���");
}
