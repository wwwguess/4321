// tisha.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����ɳֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "˫Ŀ�������޷���������\n");
		
	if( (int)me->query_skill("shenghuo-shengong", 1) < 50 )
		return notify_fail("���ʥ���񹦲�����죬����ʹ�������ɳ��\n");

	msg = CYN "$N���Ӱ�ף���������һɨ�������ϵ�ɳʯ������ͼ��ס$n���۾���
\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "���$p��$P��ס��˫�ۣ�˫Ŀ�������\n" NOR;
		target->start_busy( (int)me->query_skill("shenghuo-shengong") / 20 );
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

