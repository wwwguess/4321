// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(YEL"多情刀"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "金色的刀身发出眩目的光芒,真是一把好刀!�/\n");
		set("value", 4000);
		set("material", "greysteel");
		set("wield_msg", YEL"$N长叹一声，从空中把出一把金光
四射的宝刀接在手中。\n" NOR);
		set("unwield_msg",YEL"$N将手中的多情刀插回腰间。\n" NOR);
	}
	init_blade(50);
	setup();
}
