// ginseng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�˲�", ({ "ginseng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Լʳָ�����˲Σ���˵�������ֲ�Ʒ�����������١�\n");
		set("unit", "��");
		set("value", 3000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "atman": 5, "max_atman": 150 ]) );
		set("food_supply", 30);
	}
}
