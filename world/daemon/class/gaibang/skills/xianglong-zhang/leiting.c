//leiting.c -��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !me->query("leiting"))
		return notify_fail("����⹦��û�����ֹ��ܡ�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʩչ��������������\n");

	if (me->query_skill_mapped("force") != "huntian-qigong" || me->query_skill("force",1)/2 + me->query_skill("huntian-qigong",1) < 135 )
		return notify_fail("����ڹ��ȼ��������޷�ʩչ��������������\n");

	if (me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang",1) < 135 )
		return notify_fail("��Ľ���ʮ���Ƶȼ�������ʩչ������������������\n");

	msg = RED "$Nȫ����������Խ��һʽ����������������������$n��";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		message_vision(msg, me, target);
		target->unconcious();
	} else {
		msg += "����$p���Ƕ����$P�����һ������\n" NOR;
		message_vision(msg, me, target);
	        me->unconcious();
	}
	return 1;
}
