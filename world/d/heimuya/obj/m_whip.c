// whip.c

#include <weapon.h>

inherit WHIP;

void create()
{
    set_name( "���", ({ "whip" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("value", 50);
                set("material", "wood");
                set("rigidity", 70);
                set("wield_msg", "$N���������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
                set("long","һ�������ĳ���\n");

        }
        init_whip(1);
        setup();
}
