//OBJECT:/d/suzhou/npc/obj/stone.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLK"����ʯ"NOR, ({ "dali shi", "shi" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�黨�������Ĵ���ʯ����������װ���á�\n");
	}
        setup();
}

