// letter.c

inherit ITEM;

void create()
{
	set_name( "�������", ({ "book" }) );
	set_weight(600);
	set("unit", "��");
	set("long", "����һ���������ɡ�����֮���Ĺ��飬�����Ѿ�������ˡ�\n");
	set("value", 200);
	set("skill", ([
		"name": 		"magic",		// name of the skill
		"exp_required":	0,				// minimum combat experience required
										// to learn this skill.
		"sen_cost":		25,				// gin cost every time study this
		"difficulty":	20,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	20				// the maximum level you can learn
										// from this object.
	]) );
}
