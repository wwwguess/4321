// demon_staff.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( RED "��ħ��" NOR, ({ "demon staff", "staff" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѱ���ɫ�����ɶ೤�ľ��ơ�\n");
		set("value", 20000);
                set("material", "crimson gold");
        }
        init_staff(50);
        setup();
}

