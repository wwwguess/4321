//letter.c
//by dwolf
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( YEL"����"NOR, ({ "letter", "xin" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long",
	MAG"�����ظ��Ů��������ţ�������Щ�֡�"NOR);
                set("value", 30);
                set("material", "paper");
        }
        setup();
}
