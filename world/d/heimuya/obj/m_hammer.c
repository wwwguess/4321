
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ľ��", ({ "mu hammer", "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 16);
                set("material", "woo");
                set("long", "һ�Ѵ��\n");
        }
	init_hammer(4);
        setup();

}
