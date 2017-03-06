// mo-zhang-jue.c                 
//write by dfbb@hero
// date 1/25/97

inherit SKILL;

mapping *action = ({
([      "action": "$Nʹ��һ�С��������⡹�����ƴ�������$n��$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ����һ�Σ�һ�С�������ţ������$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "����"
]),
([	"action": "$N����һ�С����׶��¡���Ѹ���ޱȵ�����$n��$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "����"
]),
([	"action": "$N˫��ʩ��һ�С��������������������ŷ�������$n��$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$N��üһ��һ�С�����һ������������$n��$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$Nʩ��һ�С���Ը���������Ʋ�������������$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$Nʹ�������������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "����"
]),
([	"action": "$N���һ����˫��ʹ�����ƺ�֮ˮ��������������һ�а����$n",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("�����ħ�󷨹�������! �\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 10)
		return notify_fail("�������������ħ�ƾ���\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}

