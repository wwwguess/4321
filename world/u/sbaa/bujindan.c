// guiyuan.c ������ sbaa 11.8

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"bujin dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ�Ĳ�������\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
    {        
       if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
      	this_player()->add("gin",50);
	message_vision("$N����һ�Ų�������ֻ���þ���һ�𣬺�ˬ !\n", this_player());
	destruct(this_object());
	return 1;
}


