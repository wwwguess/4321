// gaodian1.c 
// by dwolf 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
set_name(MAG"ѩ�����"NOR, ({"xuehua gao" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"�����³�������ѩ���⣬���㰡��\n"NOR);
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
