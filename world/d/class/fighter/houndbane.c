// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( GRN "��������" NOR, ({ "houndbane blade", "houndbane", "blade" }) );
	set_weight(17000);
	set("unit", "��");
	set("long", "����һ�Ѱ���ɫ�Ĺ�ͷ����������������ء�\n");
	set("value", 4200000);
	set("material", "crimsonsteel");
	init_blade(96);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��쬡���һ�����һ�ѱ����б���$n�������С�\n");
	set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");

// The setup() is required.

	setup();
}
