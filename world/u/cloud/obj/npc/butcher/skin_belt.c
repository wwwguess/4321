// skin_belt.c

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( "ţƤ����", ({ "skin belt", "belt" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "skin");
                set("armor_type", "waist");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", -2);
        }
}

