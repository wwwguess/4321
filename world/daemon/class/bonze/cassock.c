// cassock.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�������", ({ "cassock" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/armor_vs_force", 80);
		set("armor_prop/composure", 10);
	}
	setup();
}
