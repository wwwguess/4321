//flag.c
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(RED"����"NOR, ({ "biao kee", "flag" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "������Զ�ھֵ�һ�����죬�����и��������֡�\n"
"		   /-----------|		\n"
"		  /------------|		\n"
"		 /     ��      |		\n"
"		/	       |		\n"
"		---------------|		\n");

		set("unit", "��");
		set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

