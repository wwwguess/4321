// yinqiang.c ����ǹ

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIW "����ǹ" NOR, ({ "liangyin qiang", "qiang" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������������ǹ,������ŷ�ֹ�ֻ����鲼\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ǹ�ҡ�\n");
        }
        init_spear(45);
        setup();
}
