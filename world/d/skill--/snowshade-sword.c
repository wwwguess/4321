// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����ɽѩӰ���еġ���˪��Ӱ����$w���ӽ������ն��$n��$l",
		"dodge":		-20,
		"damae":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�������ѩ��������Ʈ�����ߣ�����$wն��$n��$l",
		"dodge":		-30,
		"damae":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l�̳�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ������$wһ�С�������������׼$n��$lбб�̳�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��ѩӰ������\n");

	if( (string)me->query_skill_mapped("force")!= "snowshade-force")
		return notify_fail("ѩӰ�������������ɽħ�̵Ķ���ѩӰ�ķ���������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_skill_usage(string usage)
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
		return notify_fail("�����������������û�а취��ϰѩӰ������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ��ѩӰ������\n");
	return 1;
}
