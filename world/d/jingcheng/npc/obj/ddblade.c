// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(YEL"���鵶"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ɫ�ĵ�����ѣĿ�Ĺ�â,����һ�Ѻõ�!�/\n");
		set("value", 4000);
		set("material", "greysteel");
		set("wield_msg", YEL"$N��̾һ�����ӿ��аѳ�һ�ѽ��
����ı����������С�\n" NOR);
		set("unwield_msg",YEL"$N�����еĶ��鵶������䡣\n" NOR);
	}
	init_blade(50);
	setup();
}
