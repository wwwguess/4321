// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIM"�ۺ����"NOR, ({ "chou shan" }) );
        set_weight(3000);
	 if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

