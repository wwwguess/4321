// icy_cloth.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIC "��ѩ������" NOR, ({ "icy cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 40000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 5);
	}
}
