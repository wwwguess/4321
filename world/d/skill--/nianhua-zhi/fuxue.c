// fuxue.c �黨ָ ���黨��Ѩ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if((int)me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�����������ʹ���黨��Ѩ!\n");

	if((int)me->query_skill("finger") < 120)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!\n");

	if((int)me->query("force") < 300)
		return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$Nʹ���黨ָ�������黨��Ѩ������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
	{
		msg +=  HIG "���$p��$P���˸����ֲ���! \n" NOR;
		target->start_busy( (int)me->query_skill("nianhua-zhi",1) / 20 + 2);
		me->add("force", -100);
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
