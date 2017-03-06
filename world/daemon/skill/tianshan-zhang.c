// tianshan-zhang.c, based on dagou-bang.c
// by yucao

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
	"dodge": -3,
	"damage": 40,
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
	"dodge": -5,
	"damage": 45,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ɽѩ��������$n��$l",
	"dodge": -10,
	"damage": 60,
	"damage_type": "����"
]),
([	"action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
	"dodge": -5,
	"damage": 50,
	"damage_type": "����"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 80)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("���������������ɽ�ȷ���\n");
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
