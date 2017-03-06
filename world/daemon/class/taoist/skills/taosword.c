// taosword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С�Ⱥа���ס�������$w�ó�һ���������$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����ʦ�����еġ���ħ���ܡ���$wȥ�����ն��$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�������桹������һ����������$wն��$n��$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һ�С�һ����Ԫ����׼$n��$l�̳�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һ��������$wһ�С��������ӡ���׼$n��$lбб�ó�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����һָ��ʹ�������ǽ�ɷ��ն��$n��$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ����ʹһ�С���ڤ·Զ������һ������$n$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һת������$wʹһ�С����˺�һ������һ���⻡��$n��$lնȥ",
		"dodge":		-30,
		"damage":		10,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����ʦ������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ��ʦ������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("taoist") + "/taosword/" + action;
}
