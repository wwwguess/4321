// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�°�ɫ��ȹ", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��򵥵���һ���°�ɫ��ȹ�����沢û��ʲôװ�Σ����ܸ���һ���������ӵĸо���\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
//		set("armor_prop/armor", 1);
		set("armor_prop/personality", 4);
		set("female_only", 1);
	}
	setup();
}

