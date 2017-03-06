// vest.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(BLK"������"NOR, ({ "iron vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			HIM"��������Ŀ�����������ز��������ۣ����ұ�һ����·�\n"
			"����Щ������ϸһ�����������Ͽ����Ϻõ�����ɵġ�\n"NOR);
		set("unit", "��");
		set("value", 1000);
		set("material", "blacksilk");
		set("armor_prop/armor", 30);
		set("armor_prop/attack", -5);
	}
	setup();
}


