//kuihua.c
//dfbb@hero
#include <ansi.h>

//inherit SSERVER;

int exert(object me, object target)
{
        string msg;
        int count;

        if( !me->is_fighting() )
                return notify_fail("�������񹦡�ֻ����ս����ʹ�á�\n");

        if( (int)me->query("kee") < 70 ) return notify_fail("�����������\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 70 )
                return notify_fail("�������������\n");

        msg = HIY "$N���������,������ɣ�\n" NOR;

        message_vision(msg, me);
        count = (int)me->query_skill("kuihua-shengong") / 20 + 2;
        if( count > 7 ) count = 7;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();

                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N����Ʈ����������ȣ�ٿ���۽�$n�Ľ���!�\n" NOR, me);
                        break;
                } else
                        message_vision(CYN "$NѸ�����׵����˿�ȥ ...\n" NOR,me,ob);
		    	
                if( !COMBAT_D->fight(me, ob) )message_vision(CYN "$N�Ҳ���������֣�\n" NOR, me);
                me->receive_damage("kee", 10);
                me->add("force", -10);
        }

        me->start_busy(1);
        return 1;
}

