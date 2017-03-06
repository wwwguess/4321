// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鼠标", ({ "mouse" }) );
	set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "只");
		set("long", "这是一个计算机上用的鼠标，美国伯得电脑原装\n");
                set("value", 3);
                set("material", "iron");
		set("wield_msg", "$N拔下一个$n，抓着线提在手里\n");
		set("unwield_msg", "$N把$n又插回计算机的COM口\n");
        }

	init_hammer(5);
        setup();
}
