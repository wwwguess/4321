// SKILL liuyang-zhang.c

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С������۽𡹣����Ƶ�������֮�ϣ�����$n",
	"force" : 130,
	"dodge" : 20,
	"damage" : 0,
	"lvl" : 0,
	"skill_name" : "�����۽�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������ƶ���������ɫ���أ�˫����ƮƮ������$n",
	"force" : 150,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 20,
	"skill_name" : "�����ƶ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���б��·��ϼ������˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 150,
	"dodge" : 30,
	"damage" : 35,
	"lvl" : 30,
	"skill_name" : "��б��·��ϼ��",
	"damage_type" : "����"
]),

([	"action" : "$Nһ�С���������������$n��$l��������",
	"force" : 200,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([	"action" : "$Nһ�С�����һ���ͽ��ѡ���ֻ��һƬ��Ӱ����$n",
	"force" : 250,
	"dodge" : 20,
	"damage" : 10,
	"lvl" : 40,
	"skill_name" : "����һ���ͽ���",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ�С���ϼ���������$n",
	"force" : 300,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 60,
	"skill_name" : "��ϼ������",
            "damage_type" : "����"
]),
([	"action" : "$Nһ�С����ղγ��֡���ֻ��һƬ��Ӱ����$n",
	"force" : 350,
	"dodge" : 30,
	"damage" : 80,
	"lvl" : 70,
	"skill_name" : "���ղγ���",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ�ǡ���ϼ��Ѧᡡ�����$n��ͷ��",
	"force" : 350,
	"dodge" : 30,
	"damage" : 90,
	"lvl" : 80,
	"skill_name" : "��ϼ��Ѧ�",
           "damage_type" : "����"
]),
([	"action" : "$Nʩ��������������������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 400,
	"dodge" : -10,
	"damage" : 90,
	"lvl" : 90,
	"skill_name" : "���������",
            "damage_type" : "����"
]),
([	"action" : "$Nʩ���������������˫��ͬʱ����$n��$l",
	"force" : 450,
	"dodge" : -10,
	"damage" : 120,
	"lvl" : 100,
	"skill_name" : "�������",
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"||usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("liuyang-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("���������������ɽ�����ơ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
