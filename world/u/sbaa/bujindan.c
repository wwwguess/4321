// guiyuan.c 补精丹 sbaa 11.8

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("补精丹", ({"bujin dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗莹白溜圆的补精丹。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
    {        
       if (!id(arg))
	return notify_fail("你要吃什么？\n");
      	this_player()->add("gin",50);
	message_vision("$N吃下一颗补精丹，只觉得精神一震，好爽 !\n", this_player());
	destruct(this_object());
	return 1;
}


