// echowhip.c

#include <weapon.h>

inherit WHIP;

void create()
{
    set_name( "����", ({ "whip" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("value", 500);
		set("material", "leather");
		set("rigidity", 70);
		set("wield_msg", "$N���������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
    init_whip(10);
	setup();
}
