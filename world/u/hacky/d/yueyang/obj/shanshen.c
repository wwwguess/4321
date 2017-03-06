// shanshen.c ��ɽ��
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "����һ��մ��ɽ��ĳ�����ɽ��.\n");
	else {
		set("long", "����һ��մ��ɽ��ĳ�����ɽ����\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("��ɽ��", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ��.\n");
		set("value", 10000);
	}
	setup();
}

int do_eat1
(string arg)
{
    object me = this_player();
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( (int)me->query_condition("yao_drug" ) > 0 ) {
		me->add("force", -1);
 		message_vision(HIR "$N����һ����ɽ�Σ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else {
		me->set("eff_qi", (int)me->query("max_kee"));
		write("�����һ����ɽ����ֻ���û���һ����������ð������ !\n");
		write("��������ƶ�ʱ�ö��ˡ�\n");
	}

	me->apply_condition("yao_drug", 60);

	destruct(this_object());
	return 1;
}


int do_eat0(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	me->add("max_force", -1);
	message_vision(HIR "$N����һ����ɽ�Σ�ֻ���øγ���ϣ�������Ż����ʱ�����²�����\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
}

