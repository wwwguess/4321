// old_robe.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ɵ���", ({"old robe","robe"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ֲ�, ϴ�����׵ľɵ���\n");
		set("unit", "��");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", -1);
	}
	setup();
}
