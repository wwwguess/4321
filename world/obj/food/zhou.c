// xk island. zhou.c ������
// dan
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
	set_name("������", ({"laba zhou", "zhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������ڵ��࣬��ɫ���̣���ζ������\n");
		set("value", 10000);
		set("no_drop", "�������������뿪�㡣\n");
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	{
		me->add("max_force", 10);
                me->add("max_jingli",4);
		message_vision(HIG "$N����һ���ֻ࣬�������������ѵ����������棬�Ĵ�����,
�鲼������,���ڰٴ��麣��ȫ������Ȼ��� !\n" NOR, me);
	}
        me->apply_condition("bonze_drug", 6000);
        destruct(this_object());
		
	
	return 1;
}

