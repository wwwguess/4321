// mo-dao-jue.c ħ����

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wбָ��һ�С�ƽɳçç����������ˮ��һ����$n��$l��ȥ",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "ƽɳçç",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������� ��,$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N���ⲻ��, һ�С��鵶��ˮ��������һ��������$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "�鵶��ˮ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���ͷ�絶����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "��ͷ�絶",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С�������� �� ��˫�ֳ����������У�����$n���ؿ�",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С������ء����������ã����ҿ�����������$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��糸���졹�����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "�糸����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�һ����ʯ���綷��,һƬ������ĵ��⣬��$n��ȫ��ӿȥ",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "һ����ʯ���綷",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("�����ħ�󷨹�������! �\n");
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
	level   = (int) me->query_skill("mo-dao-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("�������������ħ������\n");
	me->receive_damage("kee", 25);
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
