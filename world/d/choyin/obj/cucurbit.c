// cucurbit.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�Ǻ�«", ({ "sugar cucurbit", "cucurbit", "sugar" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������˴������ε����պ�«��\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
