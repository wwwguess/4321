// jingang-quan.c -����ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С��ڻ����ġ�����ȭ���ƶ���������$n��$l",
	"force" : 180,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "�ڻ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ���һ�׶����˫�������»���ȭ�����棬��ž����",
	"force" : 200,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "�һ�׶",
        "damage_type" : "����"
]),
([	"action" : "$N�ڿշ���һʽ���˷��꡹��˫��˫���������$n�޿ɶ��",
	"force" : 230,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "�˷���",
        "damage_type" : "����"
]),
([	"action" : "$N˫���麬����Ե�³���һʽ�������ס���������$n�Ƴ�",
	"force" : 270,
        "dodge" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ����ָɽ��������$n����ǰ���",
	"force" : 320,
        "dodge" : 10,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "��ָɽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ����ȥ�޻ء�������ʮָ���$n��ȫ����ʮ����ҪѨ",
	"force" : 380,
        "dodge" : 25,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "��ȥ�޻�",
        "damage_type" : "����"
]),
([	"action" : "$N��Ŀ���ӣ�˫��������һʽ����������������˷������������ǵ�����",
	"force" : 450,
        "dodge" : 15,
	"damage": 35,
	"lvl" : 54,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ������Ц������Ȼ����$n��ǰ��",
	"force" : 530,
        "dodge" : 20,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "����Ц",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫�泤ȭ������֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ̫�泤ȭ��\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������̫�����޷���̫�泤ȭ��\n");
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
	level   = (int) me->query_skill("jingang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
	{
		if((string)me->query("gender") == "����")
			return notify_fail("�������̫���ˡ�Ъ����ɣ�����ǣ�\n");
		if((string)me->query("gender") == "Ů��")
			return notify_fail("�������̫���ˡ�Ъ����ɣ�����ǣ�\n");
	}
	if ((int)me->query("force") < 20)
		return notify_fail("�������������̫�泤ȭ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}