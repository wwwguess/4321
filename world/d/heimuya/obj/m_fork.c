// steel_fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("木叉", ({ "fork" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 34);
		set("material", "wood");
                set("long","一把木叉\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");

	}
	init_fork(1);

	setup();
}

void init()
{
	add_action("do_feng","feng");
}

int do_feng()
{
	object me;
	me =  this_player();
	me->set("max_kee",me->query("eff_kee") );
	me->set("kee",me->query("eff_kee") );
	me->set("max_sen",me->query("eff_sen") );
	me->set("sen", me->query("eff_sen") );
	me->set("jin", me->query("eff_jin") );
	me->set("max_jin", me->query("eff_jin") );
	return 1;
}
