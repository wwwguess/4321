// soulimpaler.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIW "а������" NOR, ({ "soulimpaler", "sword" }) );
	set_weight(7000);
	set("unit", "��");
	set("long", "����һ��Ѫ��ɫ�ĵĳ�����������Լ��ʮ�������ҡ�\n");
	set("value", 4000000);
	set("material", "crimsonsteel");
	init_sword(80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unequip_msg", "$N�����е�$n���뱳��Ľ��ʡ�\n");

// The setup() is required.

	setup();
}
