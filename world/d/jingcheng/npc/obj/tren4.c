// tren4.c 
// by dwolf 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"��ɮ����"NOR, ({"tang4" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"һ��������ɮ���ǣ��ÿ�ม�\n"NOR);
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
