// dumpling.c ����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;   
 
void create()
{
	set_name(RED"����"NOR, ({"dazao", "zao"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����͸�Ĵ��档\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
