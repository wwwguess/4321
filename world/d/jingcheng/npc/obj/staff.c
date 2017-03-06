// staff.c

#include <weapon.h>  
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(YEL"��ͭ����"NOR, ({ "brass staff", "staff" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ִ��ֳ����ǳ����صĻ�ͭ���ȣ�������������ͭ����\n");
		set("value", 2000);
		set("material", "brass");
		set("wield_msg", YEL"$N�ó�һ������Ȼ��$n�������С�\n"NOR);
		set("unwield_msg", YEL"$N�������е�$n��\n"NOR);
	}

	init_staff(30);
	setup();
}
