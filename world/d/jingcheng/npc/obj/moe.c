// /u/lixy/obj/moe.c
//only for lixy

#include <armor.h>
#include <ansi.h>

inherit  ARMOR;

void create()
{
        set_name(HIY"���������Ĩ��"NOR, ({ "moe" }) );
        set("value",50000);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
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
