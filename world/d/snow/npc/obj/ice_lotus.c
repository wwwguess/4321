// ice_lotus.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ѩ��", ({ "ice lotus", "lotus" }) );
	set_weight(90);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ�������ڸ�ɽ��ѩ֮�е����ҩ�ģ���˵�������ڹ�\��\n"
			"������ʿ���а�����\n");
		set("unit", "��");
		set("value", 4500);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 5, "max_force": 300 ]) );
		set("food_supply", 50);
	}
}
