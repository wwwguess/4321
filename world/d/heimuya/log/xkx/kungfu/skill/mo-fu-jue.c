// mo-dao-jue.c ħ����

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wһ����һ�С�����������$n��$l��ȥ!",
	"force" : 180,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ɽ��,$w��������,һ������ $n�ľ���",
	"force" : 190,
        "dodge" : -30,
	"damage" : 25,
	"lvl" : 8,
	"skill_name" : "������ɽ",
	"damage_type" : "����"
]),
([	"action" : "$N��������, һ�С����㰧������Ю�ž��磬����$n",
	"force" : 210,
        "dodge" : -35,
	"damage" : 35,
	"lvl" : 16,
	"skill_name" : "���㰧��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ɱ�����ơ���$w�󿪴��أ����϶��»���һ��Բ������ֱ����$n",
	"force" : 220,
        "dodge" : -15,
	"damage" : 35,
	"lvl" : 24,
	"skill_name" : "ɱ������",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С������ã�� ��˫�ֳָ�������$n���ؿ�",
	"force" : 240,
        "dodge" : -20,
	"damage" : 40,
	"lvl" : 33,
	"skill_name" : "�����ã",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С�Ұ��������������ã����ҿ�������$n",
	"force" : 260,
        "dodge" : -15,
	"damage" : 50,
	"lvl" : 42,
	"skill_name" : "Ұ������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������Ի�,$wһֱ��ǰ��Ѹ������$n��$l",
	"force" : 270,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "�����Ի�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�һ��תս��ǧ�,��ر�ɫ!�������!����$n��ȫ��!",
	"force" : 290,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "һ��תս��ǧ��",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-fu-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("�������������ħ������\n");
	me->receive_damage("kee", 25);
	return 1;
}
