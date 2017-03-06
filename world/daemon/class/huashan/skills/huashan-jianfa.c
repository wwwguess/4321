// huashan-jianfa.c ��ɽ����
inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С����Ƴ�ᶡ�������$w����$n��$l",
	"damage" : 20,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ�����з����ǡ���$w��˸����������$n��$l",
	"damage" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",
	"damage" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ��������$wʹ�����׺���ա�ֱ��$n��$l",
	"damage" : 35,
	"damage_type" : "����"
]),
([      "action" : "$N���е�$wһ�Σ�ʹ��������ӭ�͡�ֱ��$n��$l",
        "damage" : 50,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20 && (int)me->query_skill("huashan-neigong", 1) < 20)
                return notify_fail("����ڹ��ȼ�̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 20)
		return notify_fail("���������������ɽ������\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-jianfa/" + action;
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
