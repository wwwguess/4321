// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIC"ˮ������"NOR, ({"shuijing baozi", "baozi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵİ��ӡ�\n");
		set("unit", "��");
		set("value", 400);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
