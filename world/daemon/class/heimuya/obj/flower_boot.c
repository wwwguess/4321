#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(RED "�廨Ь" NOR, ({ "flower boots","boots" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2500);
                set("armor_prop/armor", 3);
        }
        setup();
}
