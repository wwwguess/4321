// mantian.c 天女散花「散花」手法
//written by tang

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「散花」手法只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，正好放暗器！\n");
		
	if( (int)me->query_skill("tiannv-sanhua", 1) < 30 )
		return notify_fail("你的天女散花不够娴熟，不会使用「散花」手法。\n");

	msg = CYN "$N以「散花」手法打出一篷暗器，企图扰乱$n的攻势。\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "结果$p被$P逼得连连后退！\n" NOR;
		target->start_busy( (int)me->query_skill("tiannv-sanhua") / 20 );
	} else {
		msg += "可是$p不慌不忙的躲开了$P的暗器。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
