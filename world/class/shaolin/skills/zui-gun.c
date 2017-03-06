// zui-gun.c -�������

inherit SKILL;

mapping *action = ({
([	"action":"�����ɺͣ�����Ȱ�������ʡ���$N����$w���ᣬ��������$n��$l",
	"force" : 180,
        "dodge" : 0,
        "parry" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "���ɺͣ�����Ȱ��������",
	"damage_type":"����"
]),
([	"action":"�����ɹã������������ɲ�����$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",
	"force" : 200,
        "dodge" : 5,
        "parry" : 10,
	"damage": 15,
	"lvl" : 20,
	"skill_name" : "���ɹã������������ɲ�",
	"damage_type":"����"
]),
([	"action":"���ܹ��ˣ�ǧ���������ѡ���$N����$w��ָ���أ���$n��$l��ȥ",
	"force" : 230,
        "dodge" : 5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "�ܹ��ˣ�ǧ����������",
	"damage_type":"����"
]),
([	"action":"�������ӣ������������������$N����$w�����˻��˸���Ȧ������$n��$l",
	"force" : 270,
        "dodge" : 5,
        "parry" : 5,
	"damage": 25,
	"lvl" : 40,
	"skill_name" : "�����ӣ��������������",
	"damage_type":"����"
]),
([	"action":"�������룬������������������$N���й������ţ�����������$n",
	"force" : 320,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 50,
	"skill_name" : "�����룬��������������",
	"damage_type":"����"
]),
([	"action":"��������ߵ���ɽ����ء���$N����֧�أ�һ��һ���������$n��$l",
	"force" : 380,
        "dodge" : 5,
        "parry" : 15,
	"damage": 35,
	"lvl" : 55,
	"skill_name" : "������ߵ���ɽ�����",
	"damage_type":"����"
]),
([	"action":"���Ź��ϣ�����ױ�����¿����$NŤ������$w�ӿ�����������$n���ؿ�",
	"force" : 450,
        "dodge" : 5,
        "parry" : 20,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "�Ź��ϣ�����ױ�����¿",
	"damage_type":"����"
]),
([	"action":"�������������������ǧ������$N�ڿն�����ɽ��Ӱ������ѹ��$n",
	"force" : 530,
        "dodge" : 10,
        "parry" : 25,
	"damage": 50,
	"lvl" : 64,
	"skill_name" : "�����������������ǧ��",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("zui-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷���������İ��ء�\n");
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
	level   = (int) me->query_skill("zui-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("����������������������\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("zui-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷���������İ��ء�\n");
	me->receive_damage("kee", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"zui-gun/" + action;
}

string *parry_msg = ({
        "$nһ��$v�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n����$v�����е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ������$N��������ȥ��\n",
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ֻӳ�$v����������ʧ��һ�Ź�â֮�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�ͻ�$N�����ţ��Ƶ�$N��;����$w��\n",
        "$n����Ϊ�����ͻ�$N������\n",
        "$n��������һ��$N$w����ƫ��$N$w��\n",
        "$n������������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա�����$N���ڳ��⡣\n",
        "$n˫ȭ�����$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
