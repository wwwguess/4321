// spicyclaw.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N����΢�֣�����һ��ʹ��һ�С��������ۡ���ץ��$n��$l",
		"dodge":		-30,
		"parry":		-70,
		"force":		160,
		"damage_type":	"ץ��"
	]),
	([	"action":		"$Nٿ��һ��ת��˫��һ����ߥ���֡�ֱ��$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"����"
	]),
	([	"action":		"$N����΢б���漴���һ�������ֺ��ƺ�צʹ��������֡�������$n��$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		120,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��������ʮ�ν�����˫�ֻ����쳣��׼$n��$lץȥ",
		"dodge":		10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"ץ��"
	]),
	([	"action":		"$N������Σ�����ƮƮ��һ�С����Ͼ��ӡ�����$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		150,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��������Ѱ�ġ������Ծ���䲻�������ǰ��׼$n$l�߳�һ��",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"����"
	]),
	([	"action":		"$N������$n$l����������һ�С����������צ����ͬһ��λץ��",
		"parry":		-90,
		"force":		100,
		"damage_type":	"ץ��"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�����������ֱ�����֡�\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("�������̫�����޷������������֡�\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		switch(random(3)) {
			case 0: return CYN "��������������һ�����죬�����ǹ����������\n" NOR;
			case 1: return CYN "$N����һ�£�$n��$l������������һ�����죡\n" NOR;
			case 2: return CYN "ֻ����$n��$l��������һ�� ...\n" NOR;
		}
	}
}
