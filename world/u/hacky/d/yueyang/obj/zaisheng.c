// zaisheng.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "����һ�Ž�������������.\n");
	else {
		set("long", "����һ�Ž������������衣\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("������", ({"zaisheng wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ž�������������.\n");
		set("value", 2000);
	}
	setup();
}

int do_eat0(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	me->add("max_force", -1);
	message_vision(HIR "$N����һ�������裬ֻ���øγ���ϣ�������Ż����ʱ�����²�����\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
}
