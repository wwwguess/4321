// kaoya.c ¿¾Ñ¼
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"ÂéÀ±¶¹¸¯"NOR, ({"mala doufu", "doufu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÏãÅçÅçµÄ¶¹¸¯¡£\n");
		set("unit", "ÅÌ");
		set("value", 700);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
}
