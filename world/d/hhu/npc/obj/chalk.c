// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("粉笔头", ({ "chalk", "knife" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "个");
		set("base_weight", 300);
		set("base_value", 80);
		set("material", "iron");
		set("long",	"粉笔头是一种用来在黑板上写字的，但它也可用来当作暗器使用。\n");
	}
	set_amount(100);
	init_throwing(20);
	setup();
}
