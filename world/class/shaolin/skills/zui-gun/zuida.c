//zuida 八仙醉打

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int skill;

        if( !target ) target = offensive_target(me);
			
	if( !(int)me->query_condition("drunk"))
		return notify_fail("你没有喝醉，如何使用八仙醉打呀？\n"); 

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("八仙醉打只能对战斗中的对手使用。\n");

	if( (int)me->query_str() < 25)
		return notify_fail("你的臂力不够，无法施展八仙醉打。\n"); 

        if( (int)me->query_skill("zui-gun", 1) + (int)me->query_skill("club", 1) /2 < 90 )
                return notify_fail("你的棍法不够娴熟，不会使用八仙醉打。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("你的混元一气功等级不够，不能使用八仙醉打。\n");

        if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
                return notify_fail("你的内力不足，无法使用八仙醉打。\n");

        msg = CYN "$N摇头晃脑显出喝醉的样子，身子轻飘飘地，使出「八仙醉打」。\n";

        me->add("force", - 500);
	skill=(int)me->query_skill("zui-gun", 1);
        message_vision(msg, me, target);

        me->add_temp("apply/str", skill/6 + (int)me->query_condition("drunk"));
        me->add_temp("apply/dex", skill/6 + (int)me->query_condition("drunk"));
        me->set_temp("zuida", 1);
        remove_call_out("remove_effect");
        call_out("remove_effect",skill/10 , me, skill/6 + (int)me->query_condition("drunk"));

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/str", - amount);
        me->add_temp("apply/dex", - amount);
        me->delete_temp("zuida");
}
