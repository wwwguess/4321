// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("���", ({ "mouse" }) );
	set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
		set("long", "����һ����������õ���꣬�������õ���ԭװ\n");
                set("value", 3);
                set("material", "iron");
		set("wield_msg", "$N����һ��$n��ץ������������\n");
		set("unwield_msg", "$N��$n�ֲ�ؼ������COM��\n");
        }

	init_hammer(5);
        setup();
}
