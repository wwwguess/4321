// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("ľ��", ({ "sword", "mu jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ��ľ��\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(2);
	setup();
}
