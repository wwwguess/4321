
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name( HIM "ºìÉ«³ñÈ¹" NOR, ({ "red dress", "dress" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 4000);
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dodge", 10);
        }
        setup();
}

