// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"�Ǵ�����"NOR, ({"tangcu liyu", "liyu"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ɫζ��ȫ���Ǵ����㡣\n");
		set("unit", "��");
		set("value", 700);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
}
