// powerup.c 太极神功加力
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me )
                return notify_fail("你只能用太极神功来提升自己的战斗力。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 40) 
                return notify_fail("你的太极神功等级不够，无法提升自己的战斗力。\n");     
        if( (int)me->query("force") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功\中了。\n");
        skill = me->query_skill("force");
        me->add("force", -100);
        me->receive_damage("kee", 0);
        message_vision(
        HIR "$N气沉丹田，运起太极神功，只觉得全身充满了力量。\n" NOR, me);
        me->add_temp("apply/attack", skill/5);
        me->add_temp("apply/dodge", skill/5);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/
5 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的太极神功运行完毕，将内力收回丹田。\n");
}
