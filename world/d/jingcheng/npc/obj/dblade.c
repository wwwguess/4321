// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"无情刀"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "冰冷的刀身发出让人胆寒的青光,让人不寒而栗�/\n");
		set("value", 40000);
		set("material", "greysteel");
		set("wield_msg", RED"$N冷笑一声，从空中把出一把寒光
四射的宝刀接在手中。\n" NOR);
		set("unwield_msg",RED"$N将手中的无情刀插回腰间。\n" NOR);
	}
	init_blade(50);
	setup();
}
