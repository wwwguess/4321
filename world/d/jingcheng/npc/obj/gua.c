// /u/lixy/obj/gua.c
//only for lixy

#include <armor.h>
#include <ansi.h>

inherit  ARMOR;

void create()
{
        set_name(CYN"ʯ���𻨰������������"NOR, ({ "gua","coat" }) );
        set("value",50000);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
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
