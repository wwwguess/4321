// sword.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIR "�佣����" NOR, ({ "sword" }) );
	set_weight(7000);
	set("unit", "��");
	set("long",
		"����һ����ľ��ɵĹŽ�����������һ����ζ�����������\�����δ��������\n"
		"�ģ�ֻ�н���������������ϡ���Ա��ϵ�׭�֣��� �� �� ��\n");
	set("value", 18000);
	set("material", "steel");
	init_sword(44);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");

// The setup() is required.

	setup();
}
