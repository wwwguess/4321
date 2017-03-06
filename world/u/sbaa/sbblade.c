// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("小楼一夜听春雨", ({ "xiao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当历害的宝刀，份量不轻。\n");
		set("value", 200000);
		set("material", "steel");
	}
	init_blade(100);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
int query_autoload() { return 1; }
