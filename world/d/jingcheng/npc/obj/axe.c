// hand_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("��ɽ��", ({ "kill axe", "axe" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "steel");
                set("long",
                        "���ָ�ͷ���г����̣���ר�������������ĸ�ͷ����ս�����൱ǿ��\n"
                        "ɱ������\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������������䡣\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
        }
	init_axe(44);
        setup();
}
