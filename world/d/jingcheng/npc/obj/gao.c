// gao.c 金创药
//created by kiss
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"天香断玉膏"NOR, ({"tianxiang gao", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包能治外伤的奇药。\n");
        set("value",100000);
	}
	setup();
}

int do_eat(string arg)
{
         object me = this_player();
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	if(this_player()->is_fighting())
		return notify_fail("战斗中不能敷药。\n");
	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("你现在不需要用天香断玉膏。\n");
	else {
              me->set("eff_kee", (int)me->query("max_kee"));
              me->set("kee", (int)me->query("max_kee"));  		
                message_vision(GRN "$N吃下一包天香断玉膏，气色看起来好多了。\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}
}

