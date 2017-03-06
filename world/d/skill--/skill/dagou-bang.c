// dagou-bang.c
// write by Xiang

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
	"force" : 50,
	"dodge": -10,
	"damage": 30,
	"lvl" : 1,
	"damage_type": "����"
]),
([	"action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
	"dodge": -20,
	"force" : 100,
	"damage": 55,
	"lvl" : 33,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
	"dodge": -30,
	"force" : 180,
	"damage": 80,
	"lvl" : 66,
	"damage_type": "����"
]),
([	"action": "$Nʩ�����������졹��$w����������$n��ȥ",
	"dodge": -20,
	"force" : 250,
	"damage": 100,
	"lvl" : 100,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("staff")) > 100 &&
	    me->query_skill("force") > 60 &&
	    me->query("force") > 100 &&
	    (string)weapon->query("id") == "yuzhu zhang" ) {
		me->add("force", -100);
		return ([
		"action": "$N�������һ����â������������ʹ���������޹���������ǵذ㹥��$n",
		"damage": 500,
		"force" : 300,
		"damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("��������������򹷰�����\n");
	me->receive_damage("kee", 40);
	return 1;
}