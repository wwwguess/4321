// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"��������"NOR, ({"mala doufu", "doufu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ķ�����\n");
		set("unit", "��");
		set("value", 700);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
}
