// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"ɰ����"NOR, ({"shaguo fan", "fan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵ�ɰ������\n");
		set("unit", "��");
		set("value", 600);
		set("food_remaining", 7);
		set("food_supply", 10);
	}
}
