// hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�����", ({ "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����������ñ�ڡ�\n");
		set("unit", "��");
		set("value", 400);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
	}
	setup();
}

