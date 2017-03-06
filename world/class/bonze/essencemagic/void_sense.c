// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( target ) return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�á�\n");
	if( me->query("atman") < 50 )
		return notify_fail("�������������\n");
	if(me->query("gin") < 50)
		return notify_fail("��ľ�������! \n");
	me->add("atman", -50);
	me->receive_damage("gin", 50);
	message_vision(HIY "$N��ϥ��������ʼ���ÿ�ʶ��ͨ��˼�붨 ...\n" NOR, me);
	if( random(me->query_skill("magic")) > (int)me->query_int() ) {
		if( random(me->query("max_atman")) < (int)me->query("atman")/2 ) {
			me->add("learned_points", 1);
			write( HIR "���������һƬ���ң����Ǳ�ܽ����ˣ�\n" NOR );
			return 1;
		}
		if( (int)me->query("potential") - (int)me->query("learned_points") < 500 ) {
			me->add("potential", random( (int)me->query_spi() / 5 ) + 1);
			write( HIG "���Ǳ������ˣ�\n" NOR );
			return 1;
		}
	}
	write("������ֻ����һ������\n");
	return 1;
}
