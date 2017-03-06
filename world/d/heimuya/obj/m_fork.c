// steel_fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("ľ��", ({ "fork" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 34);
		set("material", "wood");
                set("long","һ��ľ��\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");

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
