// vest.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(BLK"铁背心"NOR, ({ "iron vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			HIM"这件铁背心看起来黑黝黝地不怎麽起眼，而且比一般的衣服\n"
			"重了些，你仔细一看，它的质料可是上好的铁打成的。\n"NOR);
		set("unit", "件");
		set("value", 1000);
		set("material", "blacksilk");
		set("armor_prop/armor", 30);
		set("armor_prop/attack", -5);
	}
	setup();
}


