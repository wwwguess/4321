// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("õ�廨", ({ "flower", "rose" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������,���ŵĺ�õ��.\n");
		set("unit", "��");
		set("value", 15);
		set("material", "grass");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

