// guiyuan.c 丹 sbaa 11.24

inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("天香续命露", ({"tianxiang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗河海独有的天香续命露，可保命！\n");
		set("value", 500000);
	}
	setup();
}

void remove_effect(object me)
{    // object me;
    // me=this_player();

	//me->add_temp("apply/attack", - 10);
	//me->add_temp("apply/dodge", - 10);
	//me->add_temp("apply/damage", - 10);
//	me->add("bellicosity", - amount - 100);
	me->delete_temp("nodie");
      tell_object(me,"你觉得天香续命露的药力已消退了 !\n");
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,tt;   
             int aa;
        me=this_player();
      if (!id(arg))
	return notify_fail("你要吃什么？\n");
       aa=me->query_temp("nodie");
if (aa) return notify_fail("天香续命露一次只能吃一颗!\n");
     // 	this_player()->add("bellicosity",50);
        //    	me->add_temp("apply/attack", 10);
	//me->add_temp("apply/dodge", 10);
//	me->add_temp("apply/damage", 10);
	me->set_temp("nodie", 1);
  //  me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 5);
//	me->start_call_out( (: call_other,"remove_effect", me, 10 :),1);
    call_out("remove_effect",150,me);
         tt=this_object();
         tt->move("/obj/sbaa/1");
	message_vision("$N吃下一颗天香续命露！哇，死了也不怕了 !\n", this_player());
		return 1;
}
