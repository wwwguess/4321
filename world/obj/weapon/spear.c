// spear.c : an example weapon

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("��ǹ", ({ "spear","qiang" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�ǹ��������Լ�ж�ʮ�������ҡ�\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_spear(30);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ��,��$n������ǰ��\n");
	set("unwield_msg", "$N�����е�$n����\n");

// The setup() is required.

	setup();
}
