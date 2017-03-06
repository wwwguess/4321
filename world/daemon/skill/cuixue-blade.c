
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С�÷ӢѩӰ��������������$w���Ƶ���$n��$lնȥ��",
		"damage":		80,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�䵶���£�$w����һ�С�ϰϰ��������ɡ����¶�������$n��$l",
		"damage":		50,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һת��һ�С�ɽ������ͯէɨ��$w�糿¶��˸��ն��$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N�趯$w��һ�С������ױ������塹��$n��$lбб����һ��",
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ�Σ�һ�С��ͷ����ͨ�Ĵ���Ѹ�����׵�����$n��$l",
		"damage":		90,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����������զչ��һ�С�ϸ������̻�ǰ��ֱ��$n$l",
		"damage":		50,
		"damage_type":	"����"
	]),
	([	"action":		"$N�Ʋ�����ʹһ�С����ʸ���Ⱥ�������������ն��$n��$l",
		"damage":		90,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("kee") < 50 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 50);
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С�����������ī�ۡ��������е�$v����$N����ָ��\n",
	"$n���̤ǰһ����һ�С�ֻ��������Ǭ���������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
	"$n���е�$vһ�������һƬ������һ�С�����÷�Ҷ����桹������$N��ȫ��\n",
	"$n΢��һ�������е�$v����һ���⻡��һ�С�����δ������֪������$N��ȫ��Χס��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С�͵��˪����һ֦���������е�$v����$N��\n",
"$n���̤ǰ̤��һ�С���Ҫ�˿����ɫ�������е�$v����$N֮�ؾȡ�\n",
"$n���е�$vһ����һ�С����ڵ������ӡ��������$N��\n",
"$n���е�$v����һ�С����ϴ���ͷ��������$N��ȫ��Χס��\n",
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
	return 40;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 30;
}

