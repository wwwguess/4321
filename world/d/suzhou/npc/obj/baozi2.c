//OBJECT:/d/suzhou/npc/obj/baozi2.c 
//by dwolf
//97.11.4                 

#include <ansi.h>   
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(BLK"�������"NOR, ({ "gourou baozi", "baozi" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ù������ڵİ��ӡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 25);
	}
	setup();
}

