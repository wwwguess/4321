// sorrowfire.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���佣", ({ "sword of sorrowfire", "sword", "sorrowfire" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ͨ����ڣ��ִ���һ˿��ζ��������\n");
		set("value", 7800);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ����ڵ�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_sword(74);
	setup();
}
