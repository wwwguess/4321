//
// fanchang.c
// by secret
// 97-1-16
//

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

//	if( environment(me)->query("no_fight") )
//		return notify_fail("^U^B^@^O^R^[^W^\^U^]^V^W! \n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ����˭��\n");

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("�����������������������������񹥻��Է���\n");

	if( (int)me->query("force",1) < 50 )
		return notify_fail("�����������������ʹ�������������\n");

	message_vision(HIW "$N���ޱ��飬�������󳪰����$n���У�\n\n" NOR, me, target );

	if( living(target))
		if( !target->is_killing(me) )
			target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("mizongxinfa") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIW " ���Ȼ��������һƬ�հף�����������������赸������\n" NOR);
		tell_object(me, HIB "�㿴��" + target->name() + "������ĸ��������㵸��ʮ�ֿ�Ц��\n" NOR);

		target->receive_damage("gin", 10 + random((int)me->query_skill("longxiang", 1)) );
		
		if( target->query("combat_exp") >= me->query("combat_exp") )
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3));
		me->add("force", -50);

	}
	else
	{	
		message_vision(HIY "����$p��Ϊ$P����������������Ȼ��ͬ���죡\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
