//
// xiangmo-chu.c ��ս�ħ��
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N�߾�����$w��ʹ��һ�С������������ֱ��$n��$l  ",
        "skill_name" : "�������",
        "dodge" : -5,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ������շ�ħ���������趯$w��һ����$w��ɨ$n������  ",
        "skill_name" : "��շ�ħ",
        "dodge" : 5,
        "parry" : 0,
        "lvl" : 8,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N�������棬ʹ��һʽ�������������˫����$W��һ��ֱ��$n��$l  ",
        "skill_name" : "�������",
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���Ȥ��������˫�־ٹ�����$n���ɲ�  ",
        "skill_name" : "��Ȥ����",
        "dodge" : 0,
        "parry" : 10,
        "lvl" : 24,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$N�趯����$w��ʹ�����������ޡ�����ʱ��ס$n��ȫ��  ",
        "skill_name" : "��������",
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 32,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�����Ѫ������ȫ�����ض��ɣ�һ��ֱ��$n��$l  ",
        "skill_name" : "����Ѫ��",
        "dodge" : 15,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ��������ħ�����Թ�֧�أ�˫��ɴ�$n������  ",
        "skill_name" : "������ħ",
        "dodge" : 20,
        "parry" : 0,
        "lvl" : 48,
        "damage" : 150,
        "damage_type" : "����",
]),
([      "action" : "$N�������ƣ�ʹ������ħ��������������������$w��ɨ$n��$l  ",
        "skill_name" : "��ħ����",
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 56,
        "damage" : 180,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

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
	level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("������������������˽�ս�ħ�ơ�\n");
	me->receive_damage("kee", 30);
	return 1;
}

