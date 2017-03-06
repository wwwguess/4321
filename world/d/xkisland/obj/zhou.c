// xk island. zhou.c 腊八粥
// dan
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
	set_name("腊八粥", ({"laba zhou", "zhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "碗");
		set("long", "这是一碗热气腾腾的粥，颜色碧绿，气味辛辣。\n");
		set("value", 10000);
		set("no_drop", "这样东西不能离开你。\n");
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	{
		me->add("max_force", 10);
                me->add("max_jingli",4);
		message_vision(HIG "$N吃下一碗粥，只觉得体内燥热难当，真气充沛，四处流窜,
遍布奇筋八脉,终于百川归海，全身功力顿然提高 !\n" NOR, me);
	}
        me->apply_condition("bonze_drug", 6000);
        destruct(this_object());
		
	
	return 1;
}

