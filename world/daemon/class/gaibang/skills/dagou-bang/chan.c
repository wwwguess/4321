//chan.c 打狗棒法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你必须使棒能使「缠」字诀。\n");

	if( me->query_skill_mapped("staff")!="dagou-bang")
		return notify_fail("你必须使打狗棒法才能施展「缠」字诀。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if( (int)me->query_skill("dagou-bang", 1) + (int)me->query_skill("staff", 1)/2 < 100 )
                return notify_fail("你的棒法不够娴熟，不会使用「缠」字诀。\n");

        if( (int)me->query_skill(me->query_skill_mapped("force"), 1) + (int)me->query_skill("force", 1)/2 < 100 )
                return notify_fail("你的内功等级不够，无法使用「打狗棒法」。\n");

        msg = CYN "$N使出打狗棒法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) {
                msg += "结果$p被$P攻了个措手不及。\n" NOR;
                target->start_busy( (int)me->query_skill("dagou-bang") / 30 );
        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;

}
