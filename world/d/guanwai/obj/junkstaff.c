
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("ľ����" , ({ "wood staff", "staff" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ϡϡ��ľ���ȣ����滹�й�ҧ���ĺۼ���\n");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ����ϡϡ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(10);
	setup();
}
