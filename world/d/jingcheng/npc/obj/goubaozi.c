// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���������"NOR, ({"goubuli baozi", "baozi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵİ��ӡ�\n");
		set("unit", "��");
		set("value", 300);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
