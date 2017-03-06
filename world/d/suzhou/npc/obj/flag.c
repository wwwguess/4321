//flag.c
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(RED"镖旗"NOR, ({ "biao kee", "flag" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是威远镖局的一面镖旗，上面有个大大的龙字。\n"
"		   /-----------|		\n"
"		  /------------|		\n"
"		 /     龙      |		\n"
"		/	       |		\n"
"		---------------|		\n");

		set("unit", "件");
		set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

