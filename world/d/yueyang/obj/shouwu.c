// shouwu.c ������
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "����һ�ó������εĺ�����.\n");
	else {
		set("long", "����һ�ó������εĺ����ڡ�\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("������", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20000);
	}
	setup();
}

int do_eat1(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	
	if ( (int)me->query_condition("yao_drug" ) > 0 || 
			me-> query("max_force") <200 ) {
		me->add("force", -1);
 		message_vision(HIR "$N����һ�ź����ڣ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else {
		me->add("max_force", 1);
		message_vision(GRN "$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n" NOR, me);
	}
	me -> apply_condition("yao_drug", 60);
	destruct(this_object());
	return 1;
}

int do_eat0(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	me->add("max_force", -1);
 	message_vision(HIR "$N����һ�ź����ڣ�ֻ���øγ���ϣ�������Ż����ʱ�����²�����\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
}
