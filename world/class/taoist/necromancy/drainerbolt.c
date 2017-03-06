// drainerbolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if( random(me->query("max_mana")) < 50 ) {
		write("��ʧ���ˡ�\n");
		return 1;
	}

	msg = HIM "$N�����૵��������ģ�����һ�ӣ����о���һ���Ϲ�����$n��\n\n" NOR;

	ap = me->query_skill("spells");
	ap = ( ap * ap * ap / 4 ) * (int)me->query("sen") / 100;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 20 + random((int)me->query("eff_sen") / 10);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "������͡���һ�����Ϲ��$p����͸��������ϳ�һ���������߲ʹ�������������\n"
					"��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
			me->receive_heal("gin", target->receive_damage("gin", damage, me));
			target->receive_wound("gin", damage/3, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "������͡���һ�����Ϲ��$p����͸�������������Ϣ��������£�\n";
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}

