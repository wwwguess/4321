// hand_axe.c

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("���", ({ "chang ji", "ji" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "steel");
                set("long","һ�ѳ��,ð�ź������˲�������!\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
        }
	init_halberd(40);
        setup();
}
