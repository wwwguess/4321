// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("�۱�ͷ", ({ "chalk", "knife" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 300);
		set("base_value", 80);
		set("material", "iron");
		set("long",	"�۱�ͷ��һ�������ںڰ���д�ֵģ�����Ҳ��������������ʹ�á�\n");
	}
	set_amount(100);
	init_throwing(20);
	setup();
}
