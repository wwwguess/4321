//  kee/ dagou-bang.c
// write by Xiang

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
	"dodge": -10,
	"damage": 30,
	"damage_type": "����"
]),
([	"action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
	"dodge": -20,
	"damage": 40,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
	"dodge": -30,
	"damage": 50,
	"damage_type": "����"
]),
([	"action": "$Nʩ�����������졹��$w����������$n��ȥ",
	"dodge": -20,
	"damage": 40,
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
	if (random(me->query_skill("staff")) > 60 &&
	    me->query_skill("force") > 60 &&
	    me->query("force") > 100 &&
	    (string)weapon->query("id") == "yuzhu zhang" ) {
		me->add("force", -100);
		return ([
		"action": "$N�������һ����â������������ʹ���������޹���������ǵذ㹥��$n",
		"damage": 500,
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

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}

string *parry_msg = ({
        "$nһ��$v�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n����$v�����е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ������$N��������ȥ��\n",
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ֻӳ�$v����������ʧ��һ�Ź�â֮�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�ͻ�$N�����ţ��Ƶ�$N��;����$w��\n",
        "$n����Ϊ�����ͻ�$N������\n",
        "$n��������һ��$N$w����ƫ��$N$w��\n",
        "$n������������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա�����$N���ڳ��⡣\n",
        "$n˫ȭ�����$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
