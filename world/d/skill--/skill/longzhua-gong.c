// longzhua-gong.c -��צ��

inherit SKILL;

mapping *action = ({
([	"action" : "�ں��������У�$Nʹһ�С�����ʽ����˫���繳��ꫣ�����$n��$l",
	"force" : 100,
	"dodge" : 5,
	"lvl"   : 0,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N�͵���ǰԾ����һ�С�׽Ӱʽ���������߳���˫��ץ��$n������",
	"force" : 110,
	"dodge" : 5,
	"damage": 5,
	"lvl"   : 6,
	"skill_name" : "׽Ӱʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�����ʽ������$n��$l",
	"force" : 120,
	"dodge" : 10,
	"damage": 5,
	"lvl"   : 12,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N���������������ڻӣ�һ�С�����ʽ������$n�ؿ�",
	"force" : 140,
	"dodge" : 10,
	"damage": 10,
	"lvl"   : 18,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N�������գ�����������ɽ��һ�С�����ʽ�����͵ػ���$n��$l",
	"force" : 160,
	"dodge" : 15,
	"damage": 10,
	"lvl"   : 24,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N�ڲ���ǰ�����ֻ��أ�����̽����һ�С�����ʽ������$n���ɲ�",
	"force" : 190,
	"dodge" : 15,
	"damage": 15,
	"lvl"   : 30,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С�����ʽ����������$n��$l",
	"force" : 220,
	"dodge" : 20,
	"damage": 15,
	"lvl"   : 35,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С���ȱʽ������$n�Ķ���",
	"force" : 260,
	"dodge" : 20,
	"damage": 20,
	"lvl"   : 40,
	"skill_name" : "��ȱʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N����б��$n����֮�䣬һ�С�����ʽ��������ȡĿ�����ַ���$n���ɲ�",
	"force" : 300,
	"dodge" : 25,
	"damage": 20,
	"lvl"   : 45,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ָ$n�Ľ�����һ�С��ὣʽ����һ������ץ��$n���еĳ���",
	"force" : 350,
	"dodge" : 25,
	"damage": 25,
	"lvl"   : 50,
	"skill_name" : "�ὣʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����ʽ��ʹ$n��������",
	"force" : 400,
	"dodge" : 30,
	"damage": 25,
	"lvl"   : 55,
	"skill_name" : "����ʽ" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�׷��ʽ����������$n��ȫ��",
	"force" : 460,
	"dodge" : 40,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "׷��ʽ" ,		
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ��������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�����צ����\n");
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
	level   = (int) me->query_skill("longzhua-gong",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("���������������צ����\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

