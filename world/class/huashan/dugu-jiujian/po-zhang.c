#include <ansi.h>

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
                return notify_fail("「破掌式」只能对战斗中的对手使用。\n");
        if (objectp(weapon = target->query_temp("weapon")))
                return notify_fail("你的对手拿着兵器，不能使用「破掌式」。\n");
        if( (int)me->query_skill("dugu-jiujian", 1) < 70 )
                return notify_fail("你的独孤九剑不够娴熟，不会使用「破掌式」。\n");
        if( (int)me->query_temp("po") ) 
		return notify_fail("你上一招还没使完，不能再使「破掌式」。\n");

        skill = me->query_skill("sword")+me->query_skill("dugu-jiujian");

        msg = CYN "$N使出独孤九剑「破掌式」，把剑舞成一片，从一个怪异的角度直刺$n招中破绽。\n";

        me->start_busy(1);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
        {
                msg += "结果$p躲闪不及，被$P刺个正着。\n" NOR;
	        me->add_temp("apply/attack", skill/6);
        	me->add_temp("apply/dodge", skill/6);
        	me->set_temp("po", 1);
                damage = skill*(me->query("str")+me->query("force_factor"))/30;
                damage = damage/2 + random(damage);
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
        me->delete_temp("po");
        tell_object(me, "你的独孤九剑「破掌式」使完了!!!\n");
}

