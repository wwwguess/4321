// dumpling.c ����  

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"�㽶"NOR, ({"xiangjiao", "xiang","jiao"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ƴȳȵ��㽶��\n");
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
