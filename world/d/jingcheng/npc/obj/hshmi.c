// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"������"NOR, ({"huansheng mi", "mi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ס�\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 6);
		set("food_supply", 5);
	}
}
