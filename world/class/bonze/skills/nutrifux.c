// nutrifux.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹ��һ�С��ϵ��֡�������һ���������������$n��$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��һ�С��µ��֡�������һ�Σ������Ϸ�˳�ƻ���$n��$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		170,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ���������⡹��̤������$n��ǰ��һ�����ײ��$n��$l",
		"dodge":		-30,
		"parry":		20,
		"force":		150,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ϰ���һ��һͦ��ʹ������ƽ�ˡ���˫��ƽ�ƻ���$n$l",
		"dodge":		-50,
		"parry":		30,
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$N���ƻ�ס��ǰ��һ���������һ�С�б������������$n$l",
		"dodge":		-20,
		"parry":		-10,
		"force":		210,
		"damage_type":	"����"
	]),
	([	"action":		"$N˫�����˼���Ȧת��ʹ���������ѡ�����ӰƮƮ����$n$l",
		"dodge":		-30,
		"parry":		-10,
		"force":		220,
		"damage_type":	"����"
	]),
	([	"action":		"$N���١���һ�������ȿ�أ�һ�С�ƽ�������˫�����ֱ��$n$l",
		"parry":		-40,
		"force":		200,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ȭ������֡�\n");
	if( (int)me->query("bellicosity") > 50 )
		return notify_fail("���ɱ��̫�أ��޷�������ȭ��\n");
	return 1;
}

int valid_enable(string usage) { return usage=="cuff"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}
