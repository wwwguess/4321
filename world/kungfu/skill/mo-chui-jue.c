// mo-chui-jue.c ħ����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���ҵĺ�ӡ�������$w��$n��$l��ȥ",
	"force" : 220,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "��ҵĺ��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ʮ�����ҡ�,$wһ��һ��,$w����$n�ľ���",
	"force" : 230,
        "dodge" : -20,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "ʮ������",
	"damage_type" : "����"
]),
([	"action" : "$N$wһ�С����Ӣ�ۡ�������$n",
	"force" : 240,
        "dodge" : -25,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "���Ӣ��",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��һ�С�ǧ����Ȼ������$n��$l",
	"force" : 260,
        "dodge" : -25,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "ǧ����Ȼ",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С���Ҷ������ ����ͷ����$n���ؿ�",
	"force" : 280,
        "dodge" : -20,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "��Ҷ����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ŭ���񾪡�,$wЮ���֮������$n",
	"force" : 300,
        "dodge" : -20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "������ŭ����",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-chui-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 80)
		return notify_fail("�������������ħ����.\n");
	me->receive_damage("kee", 25);
	return 1;
}
