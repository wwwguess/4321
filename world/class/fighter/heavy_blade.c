// heavy_blade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( "�󻷵�", ({ "heavy blade", "blade" }) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صĴ󻷵�����������ʮ�ĸ��ֻ���\n");
		set("value", 1200);
		set("material", "steel");
		set("wield_msg", "ֻ������Ǻ������һ��������죬$N�����ж���һ�Ѿ�������Ĵ󻷵���\n");
		set("unequip_msg", "$N�����е�$n���ڱ���ĵ����ϡ�\n");
	}

	init_blade(40);
	setup();
}
