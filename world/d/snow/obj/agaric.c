// agaric.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��֥", ({ "magical agaric", "agaric" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"��֥��һ���൱�����ҩ�ģ�������\�෽ʿ������֥������Ҫ��\n"
			"ҩƷ��\n");
		set("unit", "��");
		set("value", 4000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "mana": 5, "max_mana": 150 ]) );
		set("food_supply", 30);
	}
}
