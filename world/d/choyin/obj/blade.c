// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��̴ľ��", ({ "ebony blade", "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѻ��������̴ľ������������һ�ɵ�����������\n");
		set("value", 600);
		set("material", "wood");
		set("wield_msg", "$N��쬡���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(37);
	setup();
}
