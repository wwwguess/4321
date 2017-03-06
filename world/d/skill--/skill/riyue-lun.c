//
// riyue-lun.c �����ַ�
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С������ơ����������е�$w��$n��$l��ȥ  ",
        "skill_name" : "������",
        "force" : 120,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С���ɽ���ơ���˫��һ�����趯����$w��$n��$l��ɨ  ",
        "skill_name" : "��ɽ����",
        "force" : 160,
        "dodge" : -20,
        "parry" : 20,
        "lvl" : 8,
        "damage" : 55,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С���΢�ơ����͵�һ�����������¶�������$n��$l  ",
        "skill_name" : "��΢��",
        "force" : 200,
        "dodge" : -20,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С������ơ����������֮��$wɨ��$n��$l  ",
        "skill_name" : "������",
        "force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "lvl" : 24,
        "damage" : 65,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�Բ���ơ���$w������֮����ֱ��$n��$l  ",
        "skill_name" : "Բ����",
        "force" : 280,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 32,
        "damage" : 70,
        "damage_type" : "����",
]),
([      "action" : "$NԾ���գ�ʹһ�С����ػ��ơ����߾�$w����$n��$l  ",
        "skill_name" : "���ػ���",
        "force" : 320,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 40,
        "damage" : 75,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�С�׽���ơ���б������$w����$n��$l  ",
        "skill_name" : "׽����",
        "force" : 360,
        "dodge" : -15,
        "parry" : 15,
        "lvl" : 48,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N��һ��������ʹ�����Լ��项��$wɨ��$n��ͷ��  ",
        "skill_name" : "�Լ���",
        "force" : 400,
        "dodge" : -20,
        "parry" : 15,
        "lvl" : 56,
        "damage" : 100,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
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
	level   = (int) me->query_skill("riyue-lun",1);
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
	if ((int)me->query("kee") < 50)
		return notify_fail("�����������,�����������ַ���\n");
	me->receive_damage("kee", 30);
	return 1;
}
