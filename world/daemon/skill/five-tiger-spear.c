inherit SKILL;

mapping *action = ({
	([	"action":	"$Nһ��ǹ�ˣ�һ�С��ڻ����ġ���ֱ��$n��$l��ȥ��",
		"damage":	200,
		"dodge":	70,
		"damage_type":	"����"
	]),
	([	"action":	"$N����һ�ͣ�һ�С�Ϭţ���¡�������$w���¶��ϴ���$n��$l",
		"damage":	100,
		"damage_type":	"����"
	]),
	([	"action":	"$N��ǹΪ����һ�С�§�ݴ��á�������$w�ص�һ���з���$n$l����",
		"damage":	150,
		"damage_type":	"����"
	]),
	([	"action":	"$NͻȻ����������ǹ���ߣ���$n׷ʱ����Ȼ������һǹ��������",
		"damage":	180,
		"damage_type":	"����"
	]),
});

int valid_enable(string usage)
{
	return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practive_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "spear" )
		return notify_fail("���������һ��ǹ��������ǹ����\n");
	if ((int)me->query("kee", 30))
		return notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee",40);
	return 1;
}

int effective_level() {return 25;}

string *parry_msg = ({
	"$n���һ��������һ�С�������ɽ�������е�$v��$N��$w�ܿ���\n",
	"$nʹ��һ�С�����Ѱ�ߡ���$N��$w������\n",
	"$n����΢�����е�$v�������һ�С����ر���������$N��$w����һ�ߡ�\n",
});

string *unarmed_parry_msg = ({
	"$n���е�$vһ����һ�����ǹ��, �·�������ǹ����$N��ǰ�ζ�, ֻ�ó����Ա���\n",
	"$n�����е�$v��ó���һ�㣬��ס��$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
	if (weapon)
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus() { return 30; }

int practice_bonus() { return 20; }

int black_white_ness() { return 50; }
