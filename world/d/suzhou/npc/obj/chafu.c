//OBJECT: /d/suzhou/npc/obj/chafu.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( BLK"���"NOR, ({ "cha hu", "hu" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", YEL"һֻװ��ˮ�Ĳ����"NOR);
                set("value", 1000);
        }
        setup();
}                                                    

