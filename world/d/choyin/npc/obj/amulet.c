// amulet.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("ƽ����", ({ "amulet" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ú��߰�����ƽ��������˵���Ա�а��\n");
		set("material", "paper");
		set("value", 60);
		set("armor_prop/karma", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/defense", -5);
	}
	setup();
}
