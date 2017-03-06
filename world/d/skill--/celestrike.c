// celestrike.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
		"dodge":		-30,
		"parry":		10,
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
		"dodge":		-10,
		"parry":		-30,
		"force":		270,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����а�Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
		"dodge":		-30,
		"parry":		10,
		"force":		250,
		"damage_type":	"����"
	]),
	([	"action":		"$N˫��һ��ʹ����ѩ�������¡�����׼$n��$l�����ĳ�����",
		"dodge":		10,
		"parry":		-30,
		"force":		360,
		"damage_type":	"����"
	]),
	([	"action":		"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��鶯�巽�ġ�����$n$l",
		"dodge":		-20,
		"parry":		-30,
		"force":		340,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
		"dodge":		-70,
		"parry":		-10,
		"force":		380,
		"damage_type":	"����"
	]),
	([	"action":		"$N����������һ�С����������졹˫�Ʋ����Ƴ�",
		"parry":		-40,
		"force":		420,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����а���Ʊ�����֡�\n");
	if( (int)me->query_skill("celestial", 1) < 20 )
		return notify_fail("�����а��\����㣬�޷�����а�Ʒ���\n");
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������̫�����޷�����а�Ʒ���\n");
	return 1;
}

int valid_skill_usage(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}
