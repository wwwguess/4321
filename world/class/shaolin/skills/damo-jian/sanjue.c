//sanjue.c 达摩三绝剑

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) 
		return notify_fail("你要攻击谁。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须使剑才能使「达摩三绝剑」。\n");

	if( me->query_skill_mapped("sword")!="damo-jian")
		return notify_fail("你必须使达摩剑才能施展「三绝剑」。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「达摩三绝剑」只能对战斗中的对手使用。\n");

	if( (int)me->query_dex() < 30)
		return notify_fail("你的身法不够，无法施展「达摩三绝剑」。\n"); 

        if( (int)me->query_skill("damo-jian", 1) + (int)me->query_skill("sword", 1)/2 < 135 )
                return notify_fail("你的剑法不够娴熟，不会使用「达摩三绝剑」。\n");

        if( (int)me->query_skill(me->query_skill_mapped("dodge"), 1) + (int)me->query_skill("dodge", 1)/2 < 135 )
                return notify_fail("你的轻功等级不够，无法使用「达摩三绝剑」。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("你的混元一气功等级不够，不能使用「达摩三绝剑」。\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("你的内力不足，无法使用「达摩三绝剑」。\n");

	me->add("force", -300);

        msg = CYN "$N使出「达摩三绝剑」，闪电般功向$n。\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        return 1;

}
