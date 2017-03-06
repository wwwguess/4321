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
                return notify_fail("「总诀式」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("dugu-jiujian", 1) < 100 )
                return notify_fail("你的独孤九剑不够娴熟，不会使用「总诀式」。\n");
        msg = CYN "$N使出独孤九剑「总诀式」，对$n强刺几剑。\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
	{
                msg += "结果$p被$P刺个正着。\n" NOR;
		
		damage = (int)me->query_skill("dugu-jiujian", 1);

                damage = damage/2 + random(damage);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -damage/10);

        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
	return 1;
}





