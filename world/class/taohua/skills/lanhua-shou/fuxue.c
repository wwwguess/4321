//fuxue.c ������Ѩ 
//write by lysh
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int count;
        if( !target ) 
		return notify_fail("��Ҫ��˭��Ѩ��\n");

	if( (int)me->query_con() < 25)
		return notify_fail("��ĸ��ǲ������޷�ʩչ������Ѩ��\n"); 

        if( (int)me->query_skill("lanhua-shou", 1) + (int)me->query_skill("hand", 1)/2 < 120 )
                return notify_fail("����ַ�������죬����ʹ��������Ѩ��\n");

        if( (int)me->query_skill("taohua-force", 1) < 120 )
                return notify_fail("����һ��ڹ��ȼ�����������ʹ��������Ѩ��\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("����������㣬�޷�ʹ��������Ѩ��\n");
        if (me->is_busy())
                return notify_fail("����æ����!\n");


        msg = CYN "$N����΢������黨��ʹ���黨ָ���еġ��黨��Ѩ���������������$nȫ��ҪѨ��\n";

        if( !target->is_killing(me) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);
         
        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
        {
        message_vision(msg, me,target);
        msg = CYN "$n��$N��������Ӱ������æ���ң��ֲ�����ʵ��\n" NOR;
        message_vision(msg, me,target);
        count = (int)me->query_skill("lanhua-shou") / 40 + 2;
        target->start_busy((int)me->query_skill("lanhua-shou") / 40);
        if( count > 5 ) count = 5;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();

                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N����һ�����Ĵ�$N����ӰƮ��������$N˫��������ʢ���۽�$n��ȫ��ҪѨ!�\n" NOR, me,ob);
                        break;
                } else
                        message_vision(CYN "$N����ٿȻ��ȥ ...\n" NOR,me,ob);
		    	
                if( !COMBAT_D->fight(me, ob) )message_vision(CYN "$n�������������$N�Ҳ���������֣�\n" NOR, me,ob);
                if((int)me->query("force")<50){message_vision(CYN "$N�������㣬����ʩչ������Ѩ�ˡ�\n" NOR,me);
                                               return 1;
                                               }
                me->add("force", -50);   
                }
        }
               
        else
        {
                msg += "����$n������$N����ͼ����û���ϵ���\n";
                message_vision(msg, me, target);
        }


        return 1;
}
