// icy_boot.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIC "��ѩ����ѥ" NOR, ({ "icy boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 5);
	}
}
