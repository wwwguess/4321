// bosijiu.c

#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"��˹��"NOR, ({"bosi jiu" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", WHT"һ��ƿ����������������ƣ���˹�ƣ����̲�ס����ˮ��\n"NOR);
		set("unit", "ƿ");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "��˹��",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
