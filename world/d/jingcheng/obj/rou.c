// dumpling.c ����  

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"������"NOR, ({"laoshu rou", "rou","meet"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", RED"һ����ĵ�������,ɢ�����������. \n NOR");
		set("unit", "��");
  set("value", 12000)
;
		set("food_remaining",20);
		set("food_supply", 100);
	}
}
