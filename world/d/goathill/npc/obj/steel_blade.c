// steel_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�ֵ�", ({ "steel blade", "blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 700);
		set("material", "steel");
		set("long", "һ�����صĸֵ���ĥ�������ֿ죬�������൱��ɱ������\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("weapon_prop/karma", -4);
	}
	init_blade(30);
	setup();
}
