// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"з�ư���"NOR, ({"xiehuang baozi", "baozi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵİ��ӡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
