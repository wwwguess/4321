// red_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ʺ����", ({ "crimson suit", "suit" }) );
	set_weight(6500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ʺ�ɫ�Ľ��£���������ˮ�̸�Ľ�ɫ��ѻ�պš�\n");
		set("material", "cloth");
		set("value", 2000);
		set("armor_prop/armor", 5);
		set("armor_prop/attack", 5);
		set("armor_prop/defense", -5);
	}
	setup();
}
