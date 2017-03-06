// /u/lixy/obj/tao.c
//only for lixy

#include <armor.h>
#include <ansi.h>

inherit  ARMOR;

void create()
{
        set_name(HIY"五彩"NOR+HIW"丝攒"NOR+HIR"花结"NOR+HIG"长穗"NOR
+CYN"宫绦"NOR, ({ "tao" }) );
        set("value",50000);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("material", "gold");
                set("armor_prop/armor",50);
        }
        setup();
}

string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}
