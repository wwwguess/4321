// pobian.c �Ʊ�ʽ
 
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
		return notify_fail("���Ʊ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "hammer")
		return notify_fail("�Է�û��ʹ�ֱޡ����������ò��ˡ��Ʊ�ʽ����\n");

	if( skill < 50)
		return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ʊ�ʽ����\n");

	if( me->query("force") < 50 )
		return notify_fail("��������������޷����á��Ʊ�ʽ����\n");
 
	msg = HIC "$N��ʹ���¾Ž����Ʊ�ʽ���ƽ�$n���ὣ�ó����ؽ�Ӱ������˿����$n��ȥ��\n";
	message_vision(msg, me, target);
 
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("hammer") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp)
	{
		if(userp(me))
			me->add("force",-50);
		msg = "$n��ʱ����ѹ������������һ�飬����";
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
		msg = "����$n������$N�Ľ�·�����̲�ȡ���ƣ�ʹ$N���Ʊ�ʽû�������á�\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}