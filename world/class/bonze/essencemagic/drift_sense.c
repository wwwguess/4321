// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ����ʶ��ͨ��\n");
	if( me->query("atman") < 75 )
		return notify_fail("�������������\n");
	if( target )
		return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�ã�\n");
	write("��Ҫ�ƶ�����һ������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("��ֹʩ����\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) ) {
		write("���޷����ܵ�����˵����� ....\n");
		write("��Ҫ�ƶ�����һ������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("ս�����޷�ʹ����ʶ��ͨ��\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("�������������\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N��ͷ��Ŀ����ʼʩչ��ʶ��ͨ ....\n" NOR, me);
	if( random(ob->query("max_atman")) < (int)me->query("atman") / 2 ) {
		write("����ܵ��Է������������ǲ���ǿ�ҡ�\n");
		return;
	}
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("����Ϊ����������ʧ���ˡ�\n");
		return;
	}
	message( "vision", HIY "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
		+ "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n�����ǰͻȻ����һ��ҫ�۵Ĺ�â����â�и��ֳ�һ����Ӱ��\n\n" NOR,
		environment(ob), ({ me }) );
}

