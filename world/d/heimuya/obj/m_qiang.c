// qian.c ��ǹ

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("ľǹ", ({ "mu qiang", "qiang" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ĺ�ӧǹ,������ŷ�ֹ�ֻ����鲼\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���ǹ�ҡ�\n");
	}
	init_spear(2);
	setup();
}
