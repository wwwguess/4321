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
		set("long", "这是一颗十分珍贵的大还丹。\n");
		set("value", 100000);
	}
	setup();
}
void remove_effect(object me)
{
     me->delete_temp("dahuan");
     tell_object(me,HIY "大还丹的效力开始消失了。\n" NOR);
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,dh;   
          int num=0;
          me=this_player();
      if (!id(arg))
        return notify_fail("你要吃什么？\n");
       num=me->query_temp("dahuan");
     if (num>1) { 
        tell_object(me,HIC "大还丹的效力还未完全化开，不能再吃了。\n" NOR);
        return 1;
      }
        num++;
        me->set_temp("dahuan", num);
	me->add("kee",150);
	me->add("gin",150);
	me->add("sen",75);
        call_out("remove_effect",150,me);
	message_vision("$N吃下一颗大还丹，百病全消，好爽 !\n", this_player());
        dh=this_object();
        dh->move("/obj/sbaa/1"); 
	return 1;
}

