//sougu.c �ѹ�ӥצ��

inherit SKILL;

mapping *action = ({
([	"action" : "\n$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ�С���צʽ��",
	"force" : 170,
	"dodge" : 5,
	"damage_type" : "ץ��",
	"lvl" : 0,
	"damage" : 15,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ�С���צʽ��˫צ����$n�Ժ����",
	"force" : 190,
	"dodge" : 20,
	"damage_type" : "ץ��",
	"damage" : 25,
	"lvl" : 5,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N�͵�һ����ͻȻ����$n��ǰ��ʹһ�С���צʽ������צֱ��$nС��",
	"force" : 215,
	"dodge" : 20,
	"damage_type" : "ץ��",
	"damage" : 35,
	"lvl" : 10,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N��צ���أ���צ�����󷢣�һ�С���צʽ������������$n��$l",
	"force" : 245,
	"dodge" : 5,
	"damage_type" : "ץ��",
	"damage" : 45 ,
	"lvl" : 20,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N���ι��죬����ǰ�ˣ�ʹһ�С���צʽ����ֱ��$n�ɲ�",
	"force" : 280,
	"dodge" : 25,
	"damage_type" : "ץ��",
	"damage" : 55,
	"lvl" : 35,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N����Ʈ������Ȼת��$n���һ�С���צʽ����˫צֱ��$n�ʺ����",
	"force" : 320,
	"dodge" : 35,
	"damage_type" : "ץ��",
	"damage" : 65,
	"lvl" : 60,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$Nһ����Х�����ΰ���ʹ����ǧצʽ�����ɰ�������»���$n�پ�����צӰ������ȫ����Ѩ",
	"force" : 365,
	"dodge" : 40,
	"damage_type" : "ץ��",
	"damage" : 95,
	"lvl" : 85,
	"skill_name" : "ǧצʽ"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ѹ�ӥצ��������֡�\n");
//	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
//		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�ѧ�ѹ�ӥצ����\n");
	if ((int)me->query("str") < 24)
		return notify_fail("��ı���̫��޷�ѧ�ѹ�ӥצ����\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object ob, object weapon)
{
	int i, level;
	level = (int)ob->query_skill("sougu", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sougu/" + action;
}
