//
// hujia-daofa.c 
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w���ƣ�һ�С��Ʋ�������������������$nl��ȥ  ",
        "skill_name" : "�Ʋ�����",
        "force" : 80,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 25,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�ɳŸ�Ӳ������������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���  ",
        "skill_name" : "ɳŸ�Ӳ�",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 8,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���������������$w��������һ��ѹ��$n ",
        "skill_name" : "��������",
        "force" : 120,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 35,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ȡ���$w������б����$n��ȥ ",
        "skill_name" : "��������",
        "force" : 150,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С���´��ʡ���һ���׹�����$n���ؿ� ",
        "skill_name" : "��´���",
        "force" : 200,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 32,
        "damage" : 45,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ʹ��һ�С��׺���᡹���������ã����ҿ�����������$n  ",
        "skill_name" : "�׺����",
        "force" : 230,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������ů�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l  ",
        "skill_name" : "������ů",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 48,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nļ��ʹһ�С��˷��ص�������ʱ�����������䵶��������˷�ӿ��$nȫ��  ",
        "skill_name" : "�˷��ص�",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 56,
        "damage" : 70,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) >= 20 ||
	    (int)me->query_skill("force", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
	else if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("hujia-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("������������������˺��ҵ�����\n");
	me->receive_damage("kee", 30);
	return 1;
}

