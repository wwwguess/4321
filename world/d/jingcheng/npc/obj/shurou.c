// shurou.c 
//by dwolf
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"������"NOR, ({ "shu rou", "rou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"һͷѪ���ܵ������󡣾�˵������ó�ม�\n"NOR);
		set("unit", "ͷ");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
	setup();
}

