// kaoya.c ¿¾Ñ¼
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"ÌÇ´×ÀğÓã"NOR, ({"tangcu liyu", "liyu"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÉ«Î¶¾ãÈ«µÄÌÇ´×ÀğÓã¡£\n");
		set("unit", "ÅÌ");
		set("value", 700);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
}
