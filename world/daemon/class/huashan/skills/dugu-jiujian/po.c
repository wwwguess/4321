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
                return notify_fail("���ܾ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("dugu-jiujian", 1) < 100 )
                return notify_fail("��Ķ��¾Ž�������죬����ʹ�á��ܾ�ʽ����\n");
        msg = CYN "$Nʹ�����¾Ž����ܾ�ʽ������$nǿ�̼�����\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
	{
                msg += "���$p��$P�̸����š�\n" NOR;
		
		damage = (int)me->query_skill("dugu-jiujian", 1);

                damage = damage/2 + random(damage);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -damage/10);

        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target);
	return 1;
}





