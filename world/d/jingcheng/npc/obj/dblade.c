// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"���鵶"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����ĵ��������˵��������,���˲��������/\n");
		set("value", 40000);
		set("material", "greysteel");
		set("wield_msg", RED"$N��Цһ�����ӿ��аѳ�һ�Ѻ���
����ı����������С�\n" NOR);
		set("unwield_msg",RED"$N�����е����鵶������䡣\n" NOR);
	}
	init_blade(50);
	setup();
}
