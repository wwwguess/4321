// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("��ţ��", ({ "knife" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻܷ����ĸֵ�, ���Ƕ���Щ��\n");
                set("value", 200);
                set("material", "steel");
        }
        init_dagger(10);

        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

// The setup() is required.

        setup();
}

