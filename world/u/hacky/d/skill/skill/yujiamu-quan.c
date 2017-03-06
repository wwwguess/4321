//
// yujiamu-quan.c ������ĸȭ
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N����˫ȭ��ʹ��һ�С��ඥ������ͷ����$n��$l  ",
        "skill_name" : "�ඥ",
        "force" : 240,
        "dodge" : 5,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ࡹ������һ�ͣ����ֻ���������һȭ����$n���ɲ�  ",
        "skill_name" : "���",
        "force" : 260,
        "dodge" : -5,
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��ü������ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ  ",
        "skill_name" : "�ü",
        "force" : 280,
        "dodge" : 10,
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : "$N���ι��죬ʹһ�С�������˫ȭ���»���$n��$l  ",
        "skill_name" : "���",
        "force" : 300,
        "dodge" : 5,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����š���˫ȭ������������������ֱָ$n��$l  ",
        "skill_name" : "����",
        "force" : 320,
        "dodge" : -5,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : "$N΢΢һЦ��ʹ��һʽ����������˫ȭǰ�������ֱȡ$n������  ",
        "skill_name" : "����",
        "force" : 350,
        "dodge" : 10,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ġ���ȫ��ת��˫ȭ��ɨ$n��$l  ",
        "skill_name" : "����",
        "force" : 370,
        "dodge" : 20,
        "lvl" : 48,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ��ʹ��һ�С���ʤ����һȭ�ͻ�$n�ʺ�  ",
        "skill_name" : "��ʤ",
        "force" : 450,
        "dodge" : 5,
        "lvl" : 56,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	else if ((int)me->query("max_force") < 50)
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
	level   = (int) me->query_skill("yujiamu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	if ((int)me->query("kee") < 40)
		return notify_fail("������������������˽�����ĸȭ��\n");
	me->receive_damage("kee", 20);
	return 1;
}

