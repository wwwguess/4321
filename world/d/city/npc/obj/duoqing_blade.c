// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( RED "���鵶" NOR, ({ "duoqing blade", "blade" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                    "����һ��ҫ�۵����С�\n");

                set("value", 20000);
                set("material", "steel");
                set("wield_msg",
                    "ֻ���׹�һ�֣�$N�������Ѿ�����һ��$n��\n");
                set("unequip_msg", "$N�����е�$n�������ĵ��ʡ�\n");
        }
        init_blade(35);
        setup();
}

