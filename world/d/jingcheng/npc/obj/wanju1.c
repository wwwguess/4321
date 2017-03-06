// wanju1.c //by dwolf


#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
 set_name("青葫芦", ({ "qing hulu", "hulu" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"这是一个碧绿色的葫芦，青里透黄颜色十分讨人喜爱。\n"
"葫芦上刻着许多漫画人物，挺好玩的,还可以装水。\n"NOR);
		set("unit", "个");
		set("value", 80);
		set("max_liquid", 60);
	}

		set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 60,
	]) );
}
