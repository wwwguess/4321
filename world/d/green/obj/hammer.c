#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("����", ({ "hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
	}

	init_hammer(10);
	setup();
}
