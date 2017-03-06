// breast_mirror.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("���ľ�", ({ "breast mirror", "mirror" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 800);
		set("material", "steel");
		set("unit", "��");
		set("armor_prop/armor", 25);
		set("armor_prop/armor_vs_force", 20);
		set("armor_prop/courage", 4);
		set("armor_prop/attack", -1);
	}
	setup();
}
