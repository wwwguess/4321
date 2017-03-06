// pojian.c �ƽ�ʽ
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("dugu-jiujian",1);

	if( !(me->is_fighting() ))
		return notify_fail("���ƽ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "sword")
		return notify_fail("�Է�û��ʹ�������ò��ˡ��ƽ�ʽ����\n");

	if( skill < 50)
		return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��ƽ�ʽ����\n");

	if( me->query("force") < 50 )
		return notify_fail("��������������޷����á��ƽ�ʽ����\n");

	msg = HIC "$N�ٽ�������ĬǱ���¾Ž�֮���ƽ�ʽ��, ���ལ�⣬�����̵�Ϯ��$n��\n";
	message_vision(msg, me, target);
 
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("sword") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-50);
		msg = "$n��ʱ������ǰһ��������һ�飬����";
		msg += weapon2->name();
		msg += "���ֶ�����\n" NOR;

		target->receive_damage("kee", damage);
		target->start_busy(2);
		weapon2->move(environment(me));
        }
	else
	{
		if(userp(me))
			me->add("force",-30);
		msg = "����$n������$N�Ľ�·�����̽�����" + weapon2->name() + "��÷��겻͸��ʹ$N�ġ��ƽ�ʽ��û�������á�\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}