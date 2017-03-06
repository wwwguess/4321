// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"��������",
		"action":		"$Nʹһ�С��������⡹������$w���ñ�ֱ��$n��$l��������",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"name":			"�����ѩ",
		"action":		"$N����һת��һ�С������ѩ��$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"name":			"ѩ������",
		"action":		"$N����$w��һ�С�ѩ�����桹����ӰƮ�������ص���$n��$l",
		"dodge":		-40,
		"damage":		25,
		"damage_type":	"����"
	]),
	([	"name":			"��ѩ����",
		"action":	        "$N����$wһ����һ�С���ѩ���ߡ���һ������ĽǶ���$n���̾�ȥ",
		"dodge":		-40,
		"damage":		30,
		"damage_type":	"����"
	]),
        ([
		"name":			"�����ѩ",
		"action":		"$N����һ����ʹ�С������ѩ��������$wһ�޽���һ�޲�ͣ�س���$n��$l",
		"dodge":		-50,
		"damage":		100,
		"damage_type":   "����"
        ]),
	([	"name":			"��ѩ����",
		"action":		"$Nһ�С���ѩ���ӡ�����$w���һƬ��Ӱɨ��$nȫ��",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("�������������û�а취����ѩ�޷�, ����Щ���������ɡ�\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�����������������û�а취��ϰ��ѩ�޷���\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ�麮ѩ�޷���\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

