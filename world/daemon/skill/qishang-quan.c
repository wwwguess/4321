// qishang-quan.c -����ȭ
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l",
	"force" : 180,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ�",
	"force" : 200,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "ľ�ѳ���",
        "damage_type" : "����"
]),
([	"action" : "$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���",
	"force" : 230,
	"dodge" : 15,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ��һʽ���𺣵�ɽ����˫ȭ���ջ��£��Ʋ��ɵ�",
	"force" : 270,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "�𺣵�ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����һʽ�������������ȭ���¶��ϣ�����$n",
	"force" : 320,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��һʽ������Ҳҡ�������$n����ǰ���",
	"force" : 380,
	"dodge" : 25,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "����Ҳ�",
        "damage_type" : "����"
]),
([	"action" : "$N���λ�λ������ȭ����һʽ���������ա�������˷�����ȭӰ",
	"force" : 450,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 54,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ�����߽��ˡ�����Ȼ����$n��ǰ��",
	"force" : 530,
	"dodge" : 20,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "���߽���",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
