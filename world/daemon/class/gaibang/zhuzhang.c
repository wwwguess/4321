// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({"zhuzhang", "stick"}));
        set_weight(3000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����ŻƵ����ȡ�\n");
                set("value", 1000);
                set("material", "bamboo");
                set("wield_msg", "$N���һ������ץ�����С�\n");
                set("unwield_msg", "$N�����е����Ȳ�����С�\n");
        }
        init_staff(20);
    	setup();
}
