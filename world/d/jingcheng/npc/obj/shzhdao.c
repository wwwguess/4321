// shazhu-dao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ɱ��", ({ "shazhu dao" , "dao" , "blade" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��ɱ���õ��޹Ǽ⵶��մ������Ѫ��\n");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ���������ϳ��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������ϲ��˲�������������ϡ�\n");
	}
	init_blade(5);
	setup();
}
