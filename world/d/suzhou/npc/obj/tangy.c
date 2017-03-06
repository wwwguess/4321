//OBJECT:/d/suzhou/npc/obj/tangy.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"ÌÀÔ²"NOR, ({ "tangyuan" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÏãÅçÅç£¬ÌğÌğµÄÌÀÔ²¡£\n");
		set("unit", "Íë");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
	setup();
}

