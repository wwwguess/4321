// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("新婚礼服", ({"cloth"}) );
        set("long","柔丝所制轻柔华丽的新婚礼服。\n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
		set("value",24000);
        }
        setup();
}
