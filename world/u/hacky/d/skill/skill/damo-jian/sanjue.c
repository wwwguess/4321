// sanjue.c  ��Ħ�� [��Ħ������]

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
    string msg, string1;
    int count;
 
    if( !me->is_fighting() )
	    return notify_fail("����Ħ��������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_dex() < 30)
		return notify_fail("���������, Ŀǰ������ʹ���������! \n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����, ����ʹ����һ���� !\n");

	if((int)me->query_skill("dodge") < 135)
		return notify_fail("����Ṧ��Ϊ����, ����ʹ�ô�Ħ��������\n");
 
	if((int)me->query_skill("sword") < 135)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�ô�Ħ������! \n");

    if( (int)me->query("force") < 500 )
		return notify_fail("�������������\n");


    msg = HIG "$Nʹ����Ħ���ľ�������Ħ��������������Ȼ�ӿ죡\n" NOR;
    message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("force", -150);
	me->start_busy(random(2));

    return 1;
}