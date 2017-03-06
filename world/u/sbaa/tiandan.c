// guiyuan.c 丹 sbaa 11.15

inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("天魔丹", ({"tianmo dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗河海独有的天魔丹，可提高攻击力，和杀气。\n");
		set("value", 200000);
	}
	setup();
}

void remove_effect(object me)
{    // object me;
    // me=this_player();
  	me->add_temp("apply/attack", - 10);
	me->add_temp("apply/dodge", - 10);
	me->add_temp("apply/damage", - 10);
//	me->add("bellicosity", - amount - 100);
	me->delete_temp("powerup");
      tell_object(me,"你觉得天魔丹的药力已消退了 !\n");
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,tt;   
             int aa=0;
        me=this_player();
      if (!id(arg))
	return notify_fail("你要吃什么？\n");
       aa=me->query_temp("powerup");
     if (aa>1) { 
        tell_object(me,"天魔丹吃得太多了!\n");
        me->add("kee",-200);
        return 1;
      }
      this_player()->add("bellicosity",50);
       	me->add_temp("apply/attack", 10);
	me->add_temp("apply/dodge", 10);
	me->add_temp("apply/damage", 10);
        aa=aa+1;
	me->set_temp("powerup", aa);
  //  me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 5);
//	me->start_call_out( (: call_other,"remove_effect", me, 10 :),1);
        call_out("remove_effect",150,me);
        tt=this_object();
        tt->move("/u/sbaa/t1");
	message_vision("$N吃下一颗天魔丹，只觉得血气上冲，真想杀人！ !\n", this_player());
		return 1;
}
