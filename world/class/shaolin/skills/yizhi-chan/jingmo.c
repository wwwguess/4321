//jingmo 惊魔一指

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) 
		return notify_fail("你要点谁。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("惊魔一指只能对战斗中的对手使用。\n");

	if( (int)me->query_str() < 30)
		return notify_fail("你的臂力不够，无法施展惊魔一指。\n"); 

        if( (int)me->query_skill("yizhi-chan", 1) < 90 )
                return notify_fail("你的一指禅不够娴熟，不会使用惊魔一指。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("你的混元一气功等级不够，不能使用惊魔一指。\n");

        if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
                return notify_fail("你的内力不足，无法使用惊魔一指。\n");

        msg = CYN "$N突然往前急突，使出「惊魔一指」，右手食指急点$n。\n";

        me->add("force", - 500);

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "结果$p被$P一击点中。\n" NOR;
                message_vision(msg, me, target);
                target->start_busy((int)me->query_skill("yizhi-chan") / 5);

        } else {
                msg += "可是$p早有防备，轻轻地躲开了。\n" NOR;
	        me->start_busy(10);
                message_vision(msg, me, target);
        }

        return 1;
}
