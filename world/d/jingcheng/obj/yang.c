// dumpling.c ����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"��÷"NOR, ({"yangmei", "mei"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����͸����÷��\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
