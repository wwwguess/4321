// rainwhip.c
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIM "�����" NOR, ({ "rain whip", "whip" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

	        set("unit", "��");
	        set("value", 20000);
       		set("material", "leather");
	}

	init_whip(28);

        set("wield_msg", "$N���������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

        setup();
}

