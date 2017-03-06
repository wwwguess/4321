// lingpai.c 
// Made by Ysg(1997.10.20)

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"将军府令牌"NOR, ({ "lingpai", "ling" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", YEL"这是一个金灿灿的令牌，上面刻着几个字：秦府通用。\n"NOR);
		set("value", 1000);
		set("material", "gold");
		set("no_get",0);
		set("no_drop",1);
	}
	setup();
}

