// xiaoyao-zhang

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С��������ơ�������Ю��һ�ɾ��磬ֱ��$n���Ҽ�[ȱ��Ѩ]��",
	"force" : 100,
	"dodge" : 10,
	"damage": 5,
	"lvl"   : 0,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N��ǰԾ����һ�С�����Ʒ����������һ�죬��ס��$n����ʽ������ƽ������
$n�ľ���ץȥ��",
	"force" : 150,
	"dodge" : 5,
	"damage": 10,
	"lvl"   : 10,
	"skill_name" : "Ʒ��ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С������١�����$n��$l",
	"force" : 200,
	"dodge" : 10,
	"damage": 20,
	"lvl"   : 25,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N���������������ڻӣ�һ�С��������ġ�����$n�ؿ�",
	"force" : 250,
	"dodge" : 10,
	"damage": 25,
	"lvl"   : 40,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nǰ���ŵأ�һ�С����׷�ա���������$n��ȫ��",
	"force" : 350,
	"dodge" : 40,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "׷��ʽ" ,		
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ң�Ʊ�����֡�\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("��ľ����񹦻�򲻹����޷�ѧ��ң�ơ�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�����ң�ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("xiaoyao-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("���������������ң�ơ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string *parry_msg = ({
        "ֻ�������ϡ�һ������$p���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n������$v�ܿ���\n",
        "����$n����һ�࣬������$v�񿪡�\n",
});

string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

