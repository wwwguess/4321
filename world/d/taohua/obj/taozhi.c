// taozhi_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��֦",({ "tao zhi", "zhi", "tao" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ����֦��\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(1);
        setup();
}

