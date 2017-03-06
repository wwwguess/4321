// zhutou.c ÖíÍ·

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÖíÍ·Èâ", ({ "zhu tourou", "tourou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Æ¬ÑªÁÜÁÜµÄÖíÍ·Èâ¡£\n");
		set("unit", "Æ¬");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
	setup();
}

