//fuxue.c 拈花拂穴 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「拈花拂穴」只能对战斗中的对手使用。\n");


	if( (int)me->query_str() < 25)
		return notify_fail("你的臂力不够，无法施展拈花拂穴。\n"); 

        if( (int)me->query_skill("nianhua-zhi", 1) + (int)me->query_skill("finger", 1)/2 < 90 )
                return notify_fail("你的指法不够娴熟，不会使用拈花拂穴。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 90 )
                return notify_fail("你的混元一气功等级不够，不能使用拈花拂穴。\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("你的内力不足，无法使用拈花拂穴。\n");

        msg = CYN "$N左手微伸好似拈花，使出拈花指法中的「拈花拂穴」，右手轻轻拂向$n全身要穴。\n";

        me->add("force", - 300);

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "结果$p被$P一击点中。\n" NOR;
                message_vision(msg, me, target);
                target->start_busy((int)me->query_skill("nianhua-zhi") / 10);
                target->receive_damage("kee",10);
        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                message_vision(msg, me, target);
        }

        return 1;
}
