// robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�಼����", ({"robe","cloth"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ʽ���򵥵��಼����\n");
		set("unit", "��");
		set("value", 100);
		set("armor_prop/spells", 1);
	}
	setup();
}
