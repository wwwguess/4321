#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"À·¿±Ã¿"NOR, ({"suanla tang", "suanla", "tang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“ªÕÎÀ·¿±Ã¿°£\n");
		set("unit", "ÕÎ");
		set("value", 500);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "Ã¿",
		"remaining": 15,
		"drunk_apply": 4,
	]));
}
