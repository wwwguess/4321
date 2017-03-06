// dragon_armor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_UNIQUE;

void create()
{
	set_name( HIY "ŭ������" NOR, ({ "dragon armor", "armor" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 60000);
		set("material", "goldsilk");
		set("armor_prop/armor", 50);
		set("armor_prop/armor_vs_force", 200);
		set("armor_prop/attack", 8);
	}
	setup();
}
