// boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "�׵׹�ѥ", ({ "guan boots", "boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 2800);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}
