// kaoya.c ¿¾Ñ¼
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"É°¹ø·¹"NOR, ({"shaguo fan", "fan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÈÈÆøÌÚÌÚµÄÉ°¹ø·¹¡£\n");
		set("unit", "Íë");
		set("value", 600);
		set("food_remaining", 7);
		set("food_supply", 10);
	}
}
