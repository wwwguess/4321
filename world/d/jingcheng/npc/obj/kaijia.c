// kaijia.c
//created by kiss

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(RED "金轮铠甲" NOR, ({ "kaijia", "jinlun kaijia" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
这是一件金光闪闪的铠甲，大约有二十多斤重.
LONG
     );

		set("material", "gold");
		set("unit", "件");
		set("value", 50000);
		set("wear_msg",RED "$N穿上一件闪闪发光的铠甲.\n" NOR);
		set("remove_msg", HIY "$N将金轮铠甲从身上脱了下来。\n" NOR);
		set("armor_prop/armor", 40);
	}
	setup();
}
