#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, skill;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����᳤�硹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 150 )
                return notify_fail("�������������������죬����ʹ�á����᳤�硹��\n");
        if( (int)me->query_temp("wu") ) 
		return notify_fail("����һ�л�ûʹ�꣬������ʹ�����᳤�硹��\n");

        skill = me->query_skill("sword")+me->query_skill("xuantie-jianfa");

        msg = CYN "$Nʹ������������,�����᳤�硹��ʱ������磬��һ������ķ���ֱ��$n��\n";

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
        {
                msg += "���$p��$P����Ҫ����\n" NOR;
	        me->add_temp("apply/attack", skill/6);
        	me->add_temp("apply/dodge", skill/6);
        	me->set_temp("wu", 1);
                damage = skill*(me->query("str")+me->query("jiali"))/50;
                damage = damage/2 + random(2*damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
        	remove_call_out("remove_effect");
	        call_out("remove_effect",10 , me, skill/6);


        } else {
                msg += "����$p����㿪�ˡ�\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("wu");
        tell_object(me, "����������ʹ���ˡ����᳤�硹!!!\n");
}

