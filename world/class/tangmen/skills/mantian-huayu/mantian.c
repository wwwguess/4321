// mantian.c ���컨�꡸���졹�ַ�
//written by tang

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����졹�ַ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ�����÷Ű�����\n");
		
	if( (int)me->query_skill("mantian-huayu", 1) < 30 )
		return notify_fail("������컨�겻����죬����ʹ�á����졹�ַ���\n");

	msg = CYN "$N�ԡ����졹�ַ����һ��������ͼ����$n�Ĺ��ơ�\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "���$p��$P�Ƶ��������ˣ�\n" NOR;
		target->start_busy( (int)me->query_skill("mantian-huayu") / 20 );
	} else {
		msg += "����$p���Ų�æ�Ķ㿪��$P�İ�����\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
