// echowhip.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( HIM "ħ������" NOR, ({ "echo whip", "whip" }) );
	set_weight(17000);
	set("unit", "��");
	set("value", 100000);
	set("material", "leather");
	init_whip(37);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N���������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������䡣\n");

// The setup() is required.

	setup();
}
