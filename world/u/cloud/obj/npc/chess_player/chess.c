// chess.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "chess" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"������һ�ֽ���İ�����\n");
		set("unit", "��");
		set("base_unit", "ö");
		set("base_weight", 2);
		set("base_value", 1);
	}
	set_amount(100);
	init_throwing(2);
	setup();
}
