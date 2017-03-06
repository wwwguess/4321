// qisuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭��������\n");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û���������������\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("�������ս���в�����ȡ�Է���������\n");

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������\n");

	if( (int)me->query("force",1) < 10 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");

	message_vision(
		HIR "$NͻȻ�����һЦ��˫��һ�Ĵָ��׼$n�����İ��˹�����\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		

	if( random(sp) > random(dp) )
	{
		tell_object(target, HIR "��ͻȻ����ȫ�����������Ʊ�ӿ��������֫��������Ҳʹ����������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);

		target->receive_damage("kee", (int)me->query_skill("huagong-dafa", 1) );
		me->add("kee", (int)me->query_skill("huagong-dafa", 1) );

		if( target->query("combat_exp") >= me->query("combat_exp") )
			me->add("combat_exp",1);

		me->start_busy(random(2));
		target->start_busy(random(2));
		me->add("force", -5);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->start_busy(2);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
