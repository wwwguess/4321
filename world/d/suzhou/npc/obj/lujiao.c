//OBJECT:/d/suzhou/npc/obj/lujiao.c
// by dwolf
//97.11.4

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"¹��"NOR, ({ "lu jiao", "jiao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����СС��¹�ǡ����滹����Ѫ��\n");
	}
        setup();
}

