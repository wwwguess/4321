//fuxue.c �黨��Ѩ 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���黨��Ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( (int)me->query_str() < 25)
		return notify_fail("��ı����������޷�ʩչ�黨��Ѩ��\n"); 

        if( (int)me->query_skill("nianhua-zhi", 1) + (int)me->query_skill("finger", 1)/2 < 90 )
                return notify_fail("���ָ��������죬����ʹ���黨��Ѩ��\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 90 )
                return notify_fail("��Ļ�Ԫһ�����ȼ�����������ʹ���黨��Ѩ��\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("����������㣬�޷�ʹ���黨��Ѩ��\n");

        msg = CYN "$N����΢������黨��ʹ���黨ָ���еġ��黨��Ѩ���������������$nȫ��ҪѨ��\n";

        me->add("force", - 300);

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "���$p��$Pһ�����С�\n" NOR;
                message_vision(msg, me, target);
                target->start_busy((int)me->query_skill("nianhua-zhi") / 10);
                target->receive_damage("kee",10);
        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                message_vision(msg, me, target);
        }

        return 1;
}
