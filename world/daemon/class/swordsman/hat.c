// hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "��ӧ��", ({ "white hat", "hat" }) );
	set_weight(1100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ײ���ɵĹڴ���׺��һ�����߳��İ�ӧ��\n");
		set("value", 4000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/composure", 5);
	}
	setup();
}
