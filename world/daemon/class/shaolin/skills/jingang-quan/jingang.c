//jingang.c 大金刚神通 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("大金刚神通只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("jingang-quan", 1) < 90 )
		return notify_fail("你的大金刚拳不够娴熟，不会使用大金刚神通。\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("你的混元一气功等级不够，不能使用大金刚神通。\n");

	if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
		return notify_fail("你的内力不足，无法使用大金刚神通。\n");

	msg = CYN "$N使出大金刚拳法大金刚神通，臂力大涨，全力攻向$n。\n";

	me->add("force", - 500);

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/1.5 ) {
		msg += "结果$p被$P一击命中。\n" NOR;
		message_vision(msg, me, target);
		target->die();

	} else {
		msg += "可是$p看破了$P的企图，轻轻躲开了。\n" NOR;
		message_vision(msg, me, target);
	}

	return 1;
}
