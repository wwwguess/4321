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
	set_name("补神丹", ({"busen dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗十分珍贵的补神丹。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
    {     object me,dh;   
          int num=0,sen1,sen2;
          me=this_player();
      if (!id(arg))
        return notify_fail("你要吃什么？\n");
	me->add("sen",50);
	if (me->query("sen") > me->query("max_sen") )
	{
	   num = me->query("max_sen") - me->query("sen");
           me->add("sen", num);
	}
	message_vision("$N吃下一颗补神丹，只觉得神采飞扬，好爽 !\n", this_player());
        destruct(this_object()); 
	return 1;
}

