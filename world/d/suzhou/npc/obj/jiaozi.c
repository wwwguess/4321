//OBJECT:/d/suzhou/npc/obj/jiaozi.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"����"NOR, ({ "jiaozi" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ľ��ӡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
	setup();
}

