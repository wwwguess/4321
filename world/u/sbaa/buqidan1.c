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
	set_name("������", ({"buqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ�Ĳ�������\n");
		set("value", 10);
	}
	setup();
}

int do_eat(string arg)
    {        
       if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
      	this_player()->add("kee",-100);
	message_vision("$N����һ�Ų����������ò����ͷ�����ˣ��������� !\n", this_player());
	destruct(this_object());
	return 1;
}


