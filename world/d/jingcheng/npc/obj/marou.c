// yangrou.c ÑòÈâ

#include <weapon.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÂíÈâ", ({ "ma rou", "rou" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏãÅçÅçµÄÂíÈâ¡£\n");
		set("unit", "¿é");
		set("value", 130);
		set("food_remaining", 5);
		set("food_supply", 50);
		}
	setup();
}

