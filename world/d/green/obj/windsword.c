
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( HIW "׷�罣" NOR, ({ "windsword", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ���ɫ�ĵĳ���������ȥ�����쳣��\n");
                set("value", 1000000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���뽣�ʡ�\n");
		set("weapon_prop/attack",5);
		set("weapon_prop/courage",10);
        }
        init_sword(70);
        setup();
}

