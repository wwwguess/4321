inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("雪参玉蟾丹", ({"yuchan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "丸");
		set("long", "\n这是高丽进贡的灵药，服后解毒疗伤，灵验非凡。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
/*	if(me->query("max_gin")<150)
	   {me->add("max_gin", 2);
	    me->add("eff_jing", 2);
	    me->add("gin",4);
	    me->add("max_kee",5);
	    me->add("eff_qi", 5);
	    me->add("kee",10);
	   }
	else
	   {me->add("max_gin",1);
	    me->add("eff_jing", 1);
	    me->add("gin",2);
	    me->add("max_kee",3);
	    me->add("eff_qi", 3);
	    me->add("kee",5);
	    }
*/	message_vision( "$N吃下一粒雪参玉蟾丹，只觉一股浩荡真气直涌上来，
	急忙盘膝而坐，闭目运功...\n" , me);
	destruct(this_object());
	return 1;
}