// guiyuan.c 大还丹sbaa 11.8
// solor 98.2.20
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
	set_name("大还丹", ({"dahuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", HIY "这是一颗疗伤圣品：大还丹。\n" NOR);
		set("value", 200000);
	}
	setup();
}

int do_eat(string arg)
    {     object me,dh;   
          me=this_player();
      if (!id(arg))
        return notify_fail("你要吃什么？\n");
	me->set("eff_kee",me->query("max_kee") );
	me->set("eff_gin",me->query("max_gin") );
	me->set("eff_sen",me->query("max_sen") );
	message_vision("$N吃下一颗大还丹，百病全消，好爽 !\n", this_player());
        dh=this_object();
	destruct(dh);
	return 1;
}

