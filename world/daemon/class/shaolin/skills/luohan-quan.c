// luohan-quan.c �޺�ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��$l",
	"force" : 180,
        "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "��ݺ���",
        "damage_type" : "����"
]),
([	"action" : "$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
	"force" : 200,
        "dodge" : 10,
	"lvl" : 8,
	"skill_name" : "���ﳯ��",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��ȥ",
	"force" : 220,
        "dodge" : 15,
	"lvl" : 15,
	"skill_name" : "���Ӷ�Ӧ",
        "damage_type" : "����"
]),
([	"action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��$l",
	"force" : 260,
        "dodge" : 20,
	"lvl" : 24,
	"skill_name" : "ƫ������",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 300,
        "dodge" : 25,
	"lvl" : 33,
	"skill_name" : "�ຣ��ͷ",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n������",
	"force" : 360,
        "dodge" : 30,
	"lvl" : 42,
	"skill_name" : "Юɽ����",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
	"force" : 420,
        "dodge" : 35,
	"lvl" : 50,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$N����ڿۣ�����������һʽ�������������˫�����밴��$n���ؿ�",
	"force" : 480,
        "dodge" : 40,
	"lvl" : 58,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���޺�ȭ������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�޺�ȭ��\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("�������̫�����޷����޺�ȭ��\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("luohan-quan", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷������޺�ȭ�İ��ء�\n");
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
	level   = (int) me->query_skill("luohan-quan");
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("��������������޺�ȭ��\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("luohan-quan", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷������޺�ȭ�İ��ء�\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
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
