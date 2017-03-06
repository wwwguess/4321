// poqiang.c ����ǹʽ��
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("dugu-jiujian",1);

	if( !(me->is_fighting() ))
		return notify_fail("����ǹʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| ((string)weapon2->query("skill_type") != "staff"
	&& (string)weapon2->query("skill_type") != "club"))
		return notify_fail("�Է�û��ʹǹ�������ò��ˡ���ǹʽ����\n");

	if( skill < 50)
		return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á���ǹʽ����\n");

	if( me->query("force") < 50 )
		return notify_fail("��������������޷����á���ǹʽ����\n");
 
	msg = HIC "$Nһʽ���¾Ž�����ǹʽ�����������ɵ�˳��" + weapon2->name() + "���䣬����$n����ָ��\n";
	message_vision(msg, me, target);
 
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	if((string)weapon2->query("skill_type") == "staff")
		dp = target->query_skill("staff") / 2;
	else if((string)weapon2->query("skill_type") != "club")
		dp = target->query_skill("club") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-50);
		msg = "$N������ǹʽ��, $n��ʱ������ǰһ��������һ�飬����";
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
		msg = "����$n������$N�Ľ�·������������" + weapon2->name() + "��ǰ���̣���ʹ$N�ջع���\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}