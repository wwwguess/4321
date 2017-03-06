#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	int damage;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����Ų�ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("qiankun-danuoyi", 1) < 50 )
                return notify_fail("���Ǭ����Ų�Ʋ�����죬����ʹ�á���Ų�ơ���\n");
        msg = CYN "$Nʹ��Ǭ����Ų�ơ���Ų�ơ�����$n�Ĺ��Ʒ����˻�ȥ��\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 )
	{
                msg += "���$p�Ĺ��Ʊ�$P�����˻�ȥ��\n" NOR;
		
		damage = (int)me->query_skill("qiankun-danuoyi", 1);

                damage = damage + random(damage);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -damage/10);

        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target);
	return 1;
}





