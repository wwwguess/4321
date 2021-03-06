//kuihua.c
//dfbb@hero
#include <ansi.h>

//inherit SSERVER;

int exert(object me, object target)
{
        string msg;
        int count; 
          if (me->is_busy())
                return notify_fail("你正忙着呢!\n");
        
        if( !me->is_fighting() )
                return notify_fail("「葵花神功」只能在战斗中使用。\n");

        if( (int)me->query("kee") < 70 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 70 )
                return notify_fail("你的真气不够！\n");

        msg = HIY "$N运起葵花神功,身形如飞！\n" NOR;

        message_vision(msg, me);
        count = (int)me->query_skill("kuihua-shengong") / 20 + 2;
        if( count > 7 ) count = 7;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();

                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N身形飘忽，有如鬼魅，倏地欺进$n的近身!n" NOR, me);
                        break;
                } else
                        message_vision(CYN "$N迅捷无伦地退了开去 ...\n" NOR,me,ob);
		    	
                if( !COMBAT_D->fight(me, ob) )message_vision(CYN "$N找不到机会出手！\n" NOR, me);
                me->receive_damage("kee", 10);
                me->add("force", -10);
        }

        me->start_busy(1);
        return 1;
}

