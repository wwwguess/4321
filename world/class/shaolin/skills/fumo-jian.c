// fumo-jian.c -��ħ��

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�������ơ�������ƽָ��������磬һ���ǳɺ�ɨ$n������",
	"force" : 120,
        "dodge" : -10,
	"damage" : 25,
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ�������ơ�ֱ��$n��$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 30,
	"lvl" : 10,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N�β�ͦ����һʽ����ɽ�ơ�������$w�����ޱȣ������ӽ�ײ��$n��$l",
	"force" : 170,
        "dodge" : 5,
	"damage" : 35,
	"lvl" : 20,
	"skill_name" : "��ɽ��",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�������ơ���$w������һ���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 190,
        "dodge" : 5,
	"damage" : 40,
	"lvl" : 30,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N����š���������鱧��Բ��һʽ�������ơ���$w�й�ֱ��������$n���ؿ�",
	"force" : 240,
        "dodge" : 10,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�������ơ���$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
	"force" : 280,
        "dodge" : 5,
	"damage" : 60,
	"lvl" : 49,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N����ʩ���������ơ���$w����Ƴ�һ����â��������ƿ�����$n��$l",
	"force" : 350,
        "dodge" : 5,
	"damage" : 75,
	"lvl" : 57,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N˫�Ȱ�����ף�һʽ�������ơ������⻮������ԲȦ����������������",
	"force" : 400,
        "dodge" : 5,
	"damage" : 90,
	"lvl" : 64,
	"skill_name" : "������",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="cibei-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("fumo-jian", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷����շ�ħ���İ��ء�\n");
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
	level   = (int) me->query_skill("fumo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("���������������ħ����\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("fumo-jian", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷����շ�ħ���İ��ء�\n");
	me->receive_damage("kee", 35);
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
