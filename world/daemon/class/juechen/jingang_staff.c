// jingang_staff.c
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( HIY "�����" NOR, ({ "jingang staff", "staff" }) );
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͭ�ȣ��ȵ������ƺ��������ġ�\n");
                set("value", 80000);
                set("material", "brass");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���ڵ��ϡ�\n");
                set("weapon_prop/spells",10);
                set("weapon_prop/dodge",-5);
        }
        init_staff(78);
        setup();
}

