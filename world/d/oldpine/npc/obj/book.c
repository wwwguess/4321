// phantomforce.c

inherit ITEM;

void create()
{
	set_name("��Ħ��", ({ "book" }));
	set_weight(600);
	set("unit", "��");
	set("long",
		"����ħ������������������ڹ�\�ؾ��������ķ��������м����������\n"
		"������ת����������������ķ���\n");
	set("value", 100);
	set("skill", ([
		"name": 		"phantomforce",	// name of the skill
		"exp_required":	1000000,		// minimum combat experience required
										// to learn this skill.
		"gin_cost":		30,				// gin cost every time study this
		"difficulty":	30,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	40				// the maximum level you can learn
										// from this object.
	]) );
}
