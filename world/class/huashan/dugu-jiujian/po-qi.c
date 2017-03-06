#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, skill,force;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("dugu-jiujian", 1) < 90 )
                return notify_fail("��Ķ��¾Ž�������죬����ʹ�á�����ʽ����\n");
        if( (int)me->query_temp("po") ) 
		return notify_fail("����һ�л�ûʹ�꣬������ʹ������ʽ����\n");

        skill = me->query_skill("sword")+me->query_skill("dugu-jiujian");

        msg = CYN "$Nʹ�����¾Ž�������ʽ�����ѽ����һƬ����һ������ĽǶ�ֱ��$n�����е�������\n";

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
        {
                msg += "���$p������������$P�̸����ţ���Ϣ��ɬ��\n" NOR;
	        me->add_temp("apply/attack", skill/6);
        	me->add_temp("apply/dodge", skill/6);
        	me->set_temp("po", 1);
                damage = skill*(me->query("str")+me->query("force_factor"))/30;
                damage = damage/2 + random(damage);
                force=target->query("force");
                force=force-damage;
                target->set("force", force);
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
        me->delete_temp("po");
        tell_object(me, "��Ķ��¾Ž�������ʽ��ʹ����!!!\n");
}

