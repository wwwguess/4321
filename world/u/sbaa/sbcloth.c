// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("������", ({ "dmp", "dmp cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"�����˿���Ŀ�����������ز��������ۣ���ȴ�������·�\n"
			"����ϸһ�����������Ϸǽ�ǲ���ȴ��֪��ʲ�ᶫ��������è\n"
			"����һ���Ǻö�����\n");
		set("unit", "��");
		set("value", 300000);
		set("material", "blacksilk");
		set("armor_prop/armor", 360);
		set("armor_prop/armor_vs_force",200);
//		set("armor_prop/attack", -5);
	}
	setup();
}

int query_autoload() { return 1; }
