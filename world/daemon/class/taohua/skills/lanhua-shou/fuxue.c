//fuxue.c 兰花拂穴 
//write by lysh
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int count;
        if( !target ) 
		return notify_fail("你要拂谁的穴。\n");

	if( (int)me->query_con() < 25)
		return notify_fail("你的根骨不够，无法施展兰花拂穴。\n"); 

        if( (int)me->query_skill("lanhua-shou", 1) + (int)me->query_skill("hand", 1)/2 < 120 )
                return notify_fail("你的手法不够娴熟，不会使用兰花拂穴。\n");

        if( (int)me->query_skill("taohua-force", 1) < 120 )
                return notify_fail("你的桃花内功等级不够，不能使用兰花拂穴。\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("你的内力不足，无法使用兰花拂穴。\n");
        if (me->is_busy())
                return notify_fail("你正忙着呢!\n");


        msg = CYN "$N左手微伸好似拈花，使出拈花指法中的「拈花拂穴」，右手轻轻拂向$n全身要穴。\n";

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);
         
        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
        {
        message_vision(msg, me,target);
        msg = CYN "$n被$N的重重身影攻得手忙脚乱，分不清虚实。\n" NOR;
        message_vision(msg, me,target);
        count = (int)me->query_skill("lanhua-shou") / 40 + 2;
        target->start_busy((int)me->query_skill("lanhua-shou") / 40);
        if( count > 5 ) count = 5;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();

                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N身形一闪，四处$N的身影飘忽不定，$N双手兰花般盛开欺进$n的全身要穴!n" NOR, me,ob);
                        break;
                } else
                        message_vision(CYN "$N身形倏然退去 ...\n" NOR,me,ob);
		    	
                if( !COMBAT_D->fight(me, ob) )message_vision(CYN "$n浑身毫无破绽，$N找不到机会出手！\n" NOR, me,ob);
                if((int)me->query("force")<50){message_vision(CYN "$N内力不足，不能施展兰花拂穴了。\n" NOR,me);
                                               return 1;
                                               }
                me->add("force", -50);   
                }
        }
               
        else
        {
                msg += "可是$n看破了$N的企图，并没有上当。\n";
                message_vision(msg, me, target);
        }


        return 1;
}
