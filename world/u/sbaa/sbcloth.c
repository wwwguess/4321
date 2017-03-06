// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("夺命袍", ({ "dmp", "dmp cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这件黑丝背心看起来黑黝黝地不怎麽起眼，但却是最贵的衣服\n"
			"你仔细一看，它的质料非金非帛，却不知是什麽东西，但老猫\n"
			"穿的一定是好东东。\n");
		set("unit", "件");
		set("value", 300000);
		set("material", "blacksilk");
		set("armor_prop/armor", 360);
		set("armor_prop/armor_vs_force",200);
//		set("armor_prop/attack", -5);
	}
	setup();
}

int query_autoload() { return 1; }
