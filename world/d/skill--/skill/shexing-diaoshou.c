
// shexing-diaoshou.c ���ε���

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�����߳�������������Σ���������ͻȻ����$n�ı����Ѩ",
	"force" : 90,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "���߳���",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�Σ�һʽ����ͷ��β������������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"force" : 120,
        "dodge" : 10,
	"lvl" : 10,
	"skill_name" : "��ͷ��β",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���������㡹�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"force" : 130,
        "dodge" : 20,
	"damage": 5,
	"lvl" : 20,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�������У�����ֱ����һʽ��������Ӱ������Ʈ��������$n������",
	"force" : 160,
        "dodge" : 20,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "������Ӱ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��������ܡ�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"force" : 200,
        "dodge" : 30,
	"damage": 15,
	"lvl" : 38,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���������񡹣�ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 310,
        "dodge" : 40,
	"damage": 25,
	"lvl" : 51,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ��������ӿ������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"force" : 380,
        "dodge" : 40,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "������ӿ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���������š���ȭ���������֣��������ޣ�����������$n�ĵ���",
	"force" : 460,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ε��ֱ�����֡�\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ε��֡�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷������ε��֡�\n");
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
	level   = (int) me->query_skill("shexing-diaoshou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("����������������ε��֡�\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}
