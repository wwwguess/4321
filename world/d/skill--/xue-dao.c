//
// xue-dao.c Ѫ��
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N�߾�����$w,ʹ��һ�С�ĥ��˱Ѫ����һ��б��$n��$l  ",
        "skill_name" : "ĥ��˱Ѫ",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 20,
        "damage_type" : "����",
]),
([      "action" : "$N�͵�һ����ʹһ�С���Ѫ���ء�������$w����$n�Ĵ���  ",
        "skill_name" : "��Ѫ����",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 25,
        "damage_type" : "����",
]),
([      "action" : "$N���һ�㣬ʹ����Ѫ��ãã�����������϶���ֱ��$n��$l  ",
        "skill_name" : "Ѫ��ãã",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�Ż����Ѫ������$w��������һ��ѹ��$n  ",
        "skill_name" : "Ż����Ѫ",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����ʹ����Ѫ�����ˡ�����$wֱ��$n��$l  ",
        "skill_name" : "Ѫ������",
        "force" : 250,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 32,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����Ѫ���߰ߡ�������б�̣���Ȼ����һ����ն$n������  ",
        "skill_name" : "Ѫ���߰�",
        "force" : 280,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ����Ѫ��Ѫ�����ӵ�ֱָ$n���ؿ�  ",
        "skill_name" : "��Ѫ��Ѫ",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 48,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N������㣬ʹ��һ�С�Ѫ�����桹��ת���$w����$n������  ",
        "skill_name" : "Ѫ������",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 56,
        "damage" : 100,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��\n");
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
	level   = (int) me->query_skill("xue-dao",1);
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
		return notify_fail("�������������������Ѫ����\n");
	me->receive_damage("kee", 30);
	return 1;
}

