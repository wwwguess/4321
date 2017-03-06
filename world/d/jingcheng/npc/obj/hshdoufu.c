// kaoya.c øæ—º
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"∫Ï…’∂π∏Ø"NOR, ({"hongshao doufu", "doufu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“ª≈Ãœ„≈Á≈Áµƒ∂π∏Ø°£\n");
		set("unit", "≈Ã");
		set("value", 700);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
}
