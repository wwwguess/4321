// steel_fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("��ɸֲ�", ({ "fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 3400);
		set("material", "steel");
                set("long","һ����ɸֲ�,����ð�ź������˲�������!\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");

	}
	init_fork(50);

	setup();
}
