// fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("�߹ɸֲ�", ({ "steel fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����صĴ�ֲ棬�߸���̷���������Ĺ�â��\n");
		set("value", 5100);
		set("material", "steel");
	}
	init_fork(62);

	setup();
}
