// hand_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("ľ��", ({ "mu fu", "axe" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("material", "wood");
                set("long",
                        "���ָ�ͷ���г����̣���ר����ϰ�ĸ�ͷ����ս�����൱ǿ��\n"
                        "ɱ������\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������������䡣\n");
        }
	init_axe(1);
        setup();
}
