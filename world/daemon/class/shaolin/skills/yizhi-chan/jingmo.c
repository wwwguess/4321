//jingmo ��ħһָ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) 
		return notify_fail("��Ҫ��˭��\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��ħһָֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_str() < 30)
		return notify_fail("��ı����������޷�ʩչ��ħһָ��\n"); 

        if( (int)me->query_skill("yizhi-chan", 1) < 90 )
                return notify_fail("���һָ��������죬����ʹ�þ�ħһָ��\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("��Ļ�Ԫһ�����ȼ�����������ʹ�þ�ħһָ��\n");

        if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
                return notify_fail("����������㣬�޷�ʹ�þ�ħһָ��\n");

        msg = CYN "$NͻȻ��ǰ��ͻ��ʹ������ħһָ��������ʳָ����$n��\n";

        me->add("force", - 500);

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "���$p��$Pһ�����С�\n" NOR;
                message_vision(msg, me, target);
                target->start_busy((int)me->query_skill("yizhi-chan") / 5);

        } else {
                msg += "����$p���з���������ض㿪�ˡ�\n" NOR;
	        me->start_busy(10);
                message_vision(msg, me, target);
        }

        return 1;
}
