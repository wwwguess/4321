// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name( "���¾����¾�", ({ "gin", "daode gin" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����¾����¾�����ͬ�����ʮһʼ�����ʵڰ�ʮһֹ��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"sen_cost": 20+random(20), 	// gin cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
		]) );
	}
}
