//jingang.c ������ͨ 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ֻͨ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("jingang-quan", 1) < 90 )
		return notify_fail("��Ĵ���ȭ������죬����ʹ�ô�����ͨ��\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("��Ļ�Ԫһ�����ȼ�����������ʹ�ô�����ͨ��\n");

	if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
		return notify_fail("����������㣬�޷�ʹ�ô�����ͨ��\n");

	msg = CYN "$Nʹ������ȭ��������ͨ���������ǣ�ȫ������$n��\n";

	me->add("force", - 500);

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/1.5 ) {
		msg += "���$p��$Pһ�����С�\n" NOR;
		message_vision(msg, me, target);
		target->die();

	} else {
		msg += "����$p������$P����ͼ������㿪�ˡ�\n" NOR;
		message_vision(msg, me, target);
	}

	return 1;
}
