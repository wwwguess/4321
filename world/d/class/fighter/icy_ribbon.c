// icy_band.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIC "��ѩ���ƽ�" NOR, ({ "icy ribbon", "ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 4000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 5);
	}
}
