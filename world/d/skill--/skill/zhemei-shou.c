// SKILL zhemei-shou.c

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С���÷��Թ����˫�ֺ�ӣ�ץ��$n",
	"force" : 130,
	"dodge" : 20,
	"damage" : 0,
	"lvl" : 0,
	"skill_name" : "��÷��Թ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��ƻ���Գ������ԾȻ����ץ��$n��ͷ��",
	"force" : 150,
	"dodge" : 20,
	"damage" : 20,
	"lvl" : 10,
	"skill_name" : "�ƻ���Գ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���ɽһ�����ı̡���˫�ַ׷ɣ�$nֻ���ۻ�����",
	"force" : 150,
	"dodge" : 30,
	"damage" : 30,
	"lvl" : 30,
	"skill_name" : "��ɽһ�����ı�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�÷��ѩ�串��ƻ����˫�ֺϻ���$nֻ���޴��ɱ�",
	"force" : 150,
	"dodge" : 30,
	"damage" : 45,
	"lvl" : 40,
	"skill_name" : "÷��ѩ�串��ƻ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������÷��ѩ�ҡ���˫��ƮȻץ��$n",
	"force" : 250,
	"dodge" : 30,
	"damage" : 50,
	"lvl" : 50,
	"skill_name" : "������÷��ѩ��",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�٣�һ�С�����������ŪӰ������$n",
	"force" : 300,
	"dodge" : 35,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "����������ŪӰ",
            "damage_type" : "����"
]),
([	"action" : "$Nһ�С���������ֱ���ۡ�������$n���ƺ�$n��ȫ��������",
	"force" : 350,
	"dodge" : 30,
	"damage" : 100,
	"lvl" : 70,
	"skill_name" : "��������ֱ����",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ�ǡ�����δ�϶��Ⱦ�������$n��ͷ��",
	"force" : 350,
	"dodge" : 30,
	"damage" : 150,
	"lvl" : 80,
	"skill_name" : "����δ�϶��Ⱦ�",
           "damage_type" : "����"
]),
([	"action" : "$Nʩ��������Ц�졹�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 400,
	"dodge" : -10,
	"damage" : 150,
	"lvl" : 90,
	"skill_name" : "����Ц��",
            "damage_type" : "����"
]),
([	"action" : "$Nʩ������ʯ��١�������һ������$n",
	"force" : 450,
	"dodge" : -20,
	"damage" : 150,
	"lvl" : 100,
	"skill_name" : "��ʯ���",
            "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"|| usage=="hand"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("zhemei-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("���������������ɽ��÷�֡�\n");
	me->receive_damage("kee", 25);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
