// tren3.c 
// by dwolf 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"沙僧糖人"NOR, ({"tang3" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"一个活象沙僧的糖，好酷喔。\n"NOR);
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
