//yupei.c
//by dwolf         

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( YEL"����"NOR, ({ "yupei" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
		set("long", MAG"��������ү��Ů����˼˼�����������Щ�֡�"NOR);
                set("value", 30000);
        }
        setup();
}
