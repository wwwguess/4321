
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
     set_name( HIC "��������" NOR, ({ "blue dress", "dress" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 40000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 10);
        }
   setup();
}
