// baiyunwan.c �����ܵ���

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�����ܵ���", ({"baiyunxiudan wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�������������ʥҩ��\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	this_player()->receive_curing("kee", 1000);
	this_player()->receive_curing("gin", 1000);
	this_player()->set("kee",(int)this_player()->query("max_kee"));
	this_player()->set("gin",(int)this_player()->query("max_gin"));
	message_vision("$N����һ�Ű����ܵ��裬ֻ��������������ɫ��á�\n", this_player());
	destruct(this_object());
	return 1;
	
}

