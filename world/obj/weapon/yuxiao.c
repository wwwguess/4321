// yuxiao.c ����

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(GRN "����" NOR, ({ "yu xiao", "xiao" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һ֧������ǻ�ҩʦ�����������\n");
                set("value", 100);
                set("material", "��");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�嵽����\n");
        }
        init_sword(25);
        setup();
}
