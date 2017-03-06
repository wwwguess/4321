// dun.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int busy_time, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n");

	if ( !me->is_fighting() )
		return notify_fail("�������ֻ����ս����ʹ�ã�\n");
	
	if ( target == me ) {
	        if((int)me->query("mana") < 80 )
        	        return notify_fail("��ķ���������\n");
	        if((int)me->query("sen") < 30 )
        	        return notify_fail("��ľ���û�а취��Ч���У�\n");
	        me->add("mana", -80);
	        me->receive_damage("sen", 30);
	
	        if( random(me->query_skill("spells")) < 30 ) {
	                write("��ʧ���ˡ�\n");
	                return 1;
	        }
		switch ( random(5) ) {
		case 0:
	        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
		"ֻ��$N����һ��������Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
		break ;
		case 1:
	        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
		"ֻ��$N����һ����⣬Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
		break ;
		case 2:
	        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
		"ֻ��$N����һ�Ż��棬Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
		break ;
		case 3:
	        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
		"ֻ��$N����һ�����磬Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
		break ;
		case 4:
	        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
		"ֻ��$N����һ�Ŵ���Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
		break ;
		}
	        message_vision(msg, me);
		me->move("/d/snow/temple");
		return 1 ;
	}
	if ( target->is_busy() ) {
                return notify_fail(target->name()+"���Թ˲�Ͼ���ŵ������ɡ�\n");
        }
             	
        if((int)me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 80 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");

        me->add("mana", -200);
        me->receive_damage("sen", 80);

        if( random(me->query_skill("spells")) < 40 ) {
                write("��ʧ���ˡ�\n");
                return 1;
        }
        switch ( random(5) ) {
	case 0:    
        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
	"ֻ��һ����������$n���ϣ�\n\n"NOR ;
	break ;
	case 1:
        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
	"ֻ��һ���������$n���ϣ�\n\n"NOR ;
	break;
	case 2:
        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
	"ֻ��һ�Ż�������$n���ϣ�\n\n"NOR ;
	break;
	case 3:
        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
	"ֻ����һ����Х����ˮ��$n����Χס��\n\n"NOR ;
	break;
	case 4:
        msg = HIW "$N�����૵��������ģ���Ȼ���һ����������\n"  +
	"ֻ����������������ľ������$n�������룡\n\n"NOR ;
	break;
	}
        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / 10 ) * (int)me->query("sen") / 100;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
		busy_time  = me->query("mana")/200;
		busy_time += busy_time * me->query("mana_facter") / 50 ;
		busy_time -= target->query("max_mana")/100;
		if ( busy_time < 0 ) busy_time = 0 ;
		target->start_busy(busy_time+2);
        } else {
                msg += "����$n����һԾ��������Χ����\n";
		me->start_busy(1);
	}
        message_vision(msg, me, target);
        return 1;
}

