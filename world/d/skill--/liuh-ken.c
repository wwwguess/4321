// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����ɹ��¡�����׼$n��$l��������һȭ",
		"dodge":		-40,
		"parry":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����ȭͷ��һ�С���ѩ��÷������$n��$l�к���ȥ",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ���ȭ���������Ρ���$n��$l����",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һ������ȭ��������ȭʹ������ɽ����������$n$l",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ȭ��������֡�\n");
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
	me->receive_damage("kee", 30);
	return 1;
}
