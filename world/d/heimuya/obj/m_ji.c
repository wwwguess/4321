// hand_axe.c

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("ľ�", ({ "mu ji", "ji" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50);
                set("material", "steel");
                set("long","һ��ľ�\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");
        }
	init_halberd(1);
        setup();
}
