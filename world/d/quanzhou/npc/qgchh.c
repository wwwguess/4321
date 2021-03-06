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
                return notify_fail("「气贯长虹」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 150 )
                return notify_fail("你的玄铁剑法还不够娴熟，不会使用「气贯长虹」。\n");
        if( (int)me->query_temp("wu") ) 
		return notify_fail("你上一招还没使完，不能再使「气贯长虹」。\n");

        skill = me->query_skill("sword")+me->query_skill("xuantie-jianfa");

        msg = CYN "$N使出玄铁剑法的,「气贯长虹」霎时剑气如虹，从一个绝妙的方向直刺$n。\n";

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
        {
                msg += "结果$p被$P刺中要害。\n" NOR;
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
                msg += "可是$p轻轻躲开了。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("wu");
        tell_object(me, "你收敛剑气使完了「气贯长虹」!!!\n");
}

