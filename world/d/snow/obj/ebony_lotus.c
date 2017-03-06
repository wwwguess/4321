// ebony_lotus.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ѩ��", ({ "ebony lotus", "lotus" }) );
	set_weight(90);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ�������ڸ�ɽ��ѩ֮�е����ҩ�ģ���˵�������ڹ�\��\n"
			"������ʿ���а�����\n");
		set("unit", "��");
		set("value", 30000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 60, "max_force": 2000 ]) );
		set("food_supply", 100);
	}
}
