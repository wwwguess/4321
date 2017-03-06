// dumpling.c °ü×Ó

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"ÑîÃ·"NOR, ({"yangmei", "mei"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿ÅÊìÍ¸µÄÑîÃ·¡£\n");
		set("unit", "¿Å");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
