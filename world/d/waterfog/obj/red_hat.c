// red_hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�ʺ���ڹ�", ({ "crimson hat", "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����ˮ�̸���ʿ�����ĺ�ɫԲ��ñ��ñԵ����һȦ���ߡ�\n");
		set("value", 800);
		set("armor_prop/attack", 2);
		set("armor_prop/defense", -2);
		set("armor_prop/armor", 4);
	}
	setup();
}
