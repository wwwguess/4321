// nuerh.c

#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"Ů����"NOR, ({"nerh jiu" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", BLU"������ʮ��µ�Ů���죬�������磬���Ѿ����ˡ�"NOR);
		set("unit", "ƿ");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "Ů����",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
