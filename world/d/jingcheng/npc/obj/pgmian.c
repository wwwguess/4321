// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"�Ź���"NOR, ({"paigu mian", "mian"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵ��Ź��档\n");
		set("unit", "��");
		set("value", 700);
		set("food_remaining", 7);
		set("food_supply", 10);
	}
}
