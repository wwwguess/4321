// ts-first.c
//��ɽ��÷��

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�����ᶯ����������һ̽һ�С�÷Ӱ��б����ץ��$n��$l����̬����",
		"dodge":		-30,
		"parry":		-70,
		"force":		210,
		"damage_type":	"ץ��"
	]),
	([	"action":		"$Nٿ��һ��ת��˫��һ�͡�÷��Ϯ�ˡ�ֱ��$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"����"
	]),
	([	"action":		"$N����΢б���漴���һ��������һ��ʹ����̤ѩѰ÷��������$n��$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		110,
		"damage_type":	"����"
	]),
	([	"action":		"$N˫��һ������÷�֦������һ��������˼�ĽǶȶ�׼$n��$lץȥ",
		"dodge":		10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"ץ��"
	]),
	([	"action":		"$N������Ϊ�����ƮƮ��һ�С�ӳѩ��÷������$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		250,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����÷�������������Ծ���䲻�������ǰ��׼$n$l�ĳ�һ��",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"����"
	]),
	([	"action":		"$N������$n$l����������һ�С�÷�޺��ӡ���������ͬһ��λץ��",
		"parry":		-90,
		"force":		150,
		"damage_type":	"����"
	]),
	([	"action":		"$N������ҡ������ʹ�������㸡����������һ������$n��$l",
		"parry":		-90,
		"force":		360,
		"damage_type":	"����"
	]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������˪���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("������������˪���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 80) / 2 );
		switch(random(5)) {
			case 0: return "��������������һ�����쪬�����ǹ����������\n";
			case 1: return "$N����һ�ª�$n��$l������������һ�����좦\n";
			case 2: return "ֻ����$n��$l��������һ�� ...\n";
			case 3: return "$N��˫����ͬһ������һ����Ѹ�����׵ػ���$n��$l��\n";
			case 4: return "��ɽ��÷�ֹ�Ȼ�����鴫��$n��$l���̱�ӡ��һ�ǣ�\n";
		}
	}
}

