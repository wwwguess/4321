// robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ڲ�����", ({"robe","cloth"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ʽ���򵥵ĺڲ�����\n");
		set("unit", "��");
		set("value", 100);
		set("armor_prop/spells", 2);
	}
	setup();
}
