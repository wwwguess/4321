// hand_axe.c

#include <weapon.h>

inherit HOOK;

void create()
{
        set_name("ľ��", ({ "mu gou", "gou" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50);
                set("material", "wood");
                set("long","һ��ľ��\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������������䡣\n");
        }
	init_hook(1);
        setup();
}
