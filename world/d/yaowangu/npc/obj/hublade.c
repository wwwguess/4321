//OBJ:/d/fgszhuang/npc/obj/hublade.c 
//by dwolf
//97.11.4

#include <weapon.h> 
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"胡家刀"NOR, ({ "hujia blade", "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",  "这是一把锋利的刀，只见刀身雪亮，发出耀眼的光芒，令人不敢逼视.\n");
		set("value", 24000);
		set("material", "greysteel");
		set("wield_msg", YEL"只见刀光一闪，$N的手中已经多了一把寒光四射的宝刀。\n" NOR);
		set("unwield_msg", MAG"刀光一闪，宝刀已不见了.\n" NOR);
	}
	init_blade(300);
	setup();
}
