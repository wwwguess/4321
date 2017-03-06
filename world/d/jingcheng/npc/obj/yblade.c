// yblade.c

#include <weapon.h> 
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(CYN"鸳鸯刀"NOR, ({ "yuanyang blade", "blade" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", 
YEL"这就是著名的鸳鸯刀，只见刀身雪亮，发出耀眼的光芒，令人不敢逼视.\n"NOR);
		set("value", 3000);
		set("material", "greysteel");
		set("wield_msg", MAG"只见刀光一闪，$N的手中已经多了一把寒光
四射的宝刀——$n。\n" NOR);
		set("unwield_msg", MAG"刀光一闪，鸳鸯刀已不见了.\n" NOR);
	}
	init_blade(50);
	setup();
}
