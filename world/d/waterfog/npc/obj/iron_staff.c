// iron_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������", ({ "iron staff", "staff" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������ȹ⿴��֪���ǳ����أ����������֪���������и��ء�\n");
		set("value", 2800);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ���������$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(54);
	setup();
}
