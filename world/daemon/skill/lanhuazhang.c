
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����Ϳ���Է������׼$n��$l��ƮƮ��ɨȥ",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������֣�һ�С��羰������������$n��$l��ȥ",
		"dodge":		-10,
		"parry":		10,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ����֡�ӳͥ��ǳɫ����$n��$l����",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"����"
	]),
        ([      "action":               "$N����΢�֣�����һ��ʹ��һ�С���¶�����⡹��ץ��$n��$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$Nٿ��һ��ת��˫��һ���������β�Ӱ��ֱ��$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�����ƮƮ��һ�С��紫�����㡹����$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������$n$l����������һ�С�����Ⱥ���ۡ���צ����ͬһ��λץ��",
                "parry":                -50,
                "force":                60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$N������Σ������ճ�ȭ��һ�С��������ҷ�������$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������Ʊ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$nһ�С������ǳ�ϡ����������$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n������ϣ�����һ�С����Թ����롹���Ƶ�$N����������\n",
        "$n����Ϊ����һ�С����㲻��֪�������$N��$w������\n",
        "$nһ�С�ɫǳ�����������һ��$N��$w���֣���ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�ʫ������ѡ����Ƶ�$N��;���С�\n",
        "$n����������һ�С�����ռ���Ρ�����$N֮�ؾȡ�\n",
        "$n���ַ��£�����һ�С�������ϸϸ������$N���ڳ��⡣\n",
        "$n˫�������ʹ��һ�С��ζ��Ǽ��ݡ���$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 30;
}

