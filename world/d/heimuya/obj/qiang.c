// qiang.c ��ǹ

#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("��ǹ", ({ "chang qiang", "qiang" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�ĺ�ӧǹ,������ŷ�ֹ�ֻ����鲼\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ǹ�ҡ�\n");
        }
        init_spear(25);
        setup();
}
