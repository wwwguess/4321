//chan.c �򹷰����������־�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("�����ʹ����ʹ�������־���\n");

	if( me->query_skill_mapped("staff")!="dagou-bang")
		return notify_fail("�����ʹ�򹷰�������ʩչ�������־���\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if( (int)me->query_skill("dagou-bang", 1) + (int)me->query_skill("staff", 1)/2 < 100 )
                return notify_fail("��İ���������죬����ʹ�á������־���\n");

        if( (int)me->query_skill(me->query_skill_mapped("force"), 1) + (int)me->query_skill("force", 1)/2 < 100 )
                return notify_fail("����ڹ��ȼ��������޷�ʹ�á��򹷰�������\n");

        msg = CYN "$Nʹ���򹷰����������־�����������������ͼ����$n�Ĺ��ơ�\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) {
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                target->start_busy( (int)me->query_skill("dagou-bang") / 30 );
        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;

}
