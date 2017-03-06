// mo-qian-jue.c ħǹ��

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$w���죬һ�С����Ī���������ƻԻ�,һ$w��$n��$l��ȥ",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "���Ī��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������ͻ��� ,��$wһ������������һ��ǹ��,����$n��$l",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "�����ͻ�",
	"damage_type" : "����"
]),
([	"action" : "$N���һ��! һ�С�Ϧ�ܳ��ߡ�,��$wʹ����ͬһ�����ߴ���$n��$l",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "Ϧ�ܳ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ĥ��˱Ѫ����$w������һ���һ��Բ��������$n��$l",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "ĥ��˱Ѫ",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С�ɱ�����项 ��˫�ֳ�$w����$n��$l",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "ɱ������",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С�������������ǹ����������$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����ɵ��ҡ�,$wֻ��һ���ɷ�����$n��$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "���ɵ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����֮����������졹,ǹ������,����ɷ���$n��$l��ȥ",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "���֮�����������",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "qian" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-qian-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "qian")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("�������������ħ������\n");
	me->receive_damage("kee", 25);
	return 1;
}
