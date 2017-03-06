// mo-cha-jue.c ħ���

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wһ����һ�С����������֡���$n��$lͱȥ!",
	"force" : 100,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "����������",
	"damage_type" : "����"
]),
([	"action" : "$N һ�С��������ޡ���$wЮ�ž��磬����$n",
	"force" : 280,
        "dodge" : -35,
	"damage" : 35,
	"lvl" : 16,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����紵Ѫ�ȡ�����$w���в�����$n��$l",
	"force" : 260,
        "dodge" : -25,
	"damage" : 35,
	"lvl" : 24,
	"skill_name" : "���紵Ѫ��",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "fork" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("�����ħ�󷨹�������! �\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("mo-cha-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "cha")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("�������������ħ�����\n");
	me->receive_damage("kee", 25);
	return 1;
}
