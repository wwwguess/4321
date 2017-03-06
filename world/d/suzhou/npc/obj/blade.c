//OBJ:/d/suzhou/npc/obj/blade.c 
//by dwolf
//97.11.4

#include <weapon.h> 
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(CYN"佩刀"NOR, ({ "pei blade", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",  "这是一把锋利的佩刀，只见刀身雪亮，发出耀眼的光芒，令人不敢逼视.\n");
		set("value", 2400);
		set("material", "greysteel");
		set("wield_msg", "$N抽出一把锋利的佩刀。\n");
		set("unwield_msg", "$N把佩刀插入腰间。.\n");
	}
	init_blade(80);
	setup();
}
