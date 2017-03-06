// taiji-quan.c ̫��ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���ȸβ����˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "��ȸβ",
	"damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ�С�˫����������$n��$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "˫����",
        "damage_type" : "����"
]),
([	"action" : "$N�����黮������һ�ǡ�ָ�ɴ�������$n���ɲ�",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "ָ�ɴ�",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��������ʽ�������ֻ���$n��$l�����ֹ���$n���ɲ�",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "����ʽ",
        "damage_type" : "����"
])
});

   int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
        if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-quan", 1) && (int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("���̫���񹦻�򲻹����޷�����̫��ȭ�����һ�����ⲻ������Բת�ᴮ�����ϲ���������.\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������̫��ȭ��\n");
        if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-quan", 1) && (int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("���̫���񹦻�򲻹����޷�����̫��ȭ�����һ�����ⲻ������Բת�ᴮ�����ϲ���������.\n");
	me->receive_damage("kee", 25);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

string *parry_msg = ({
        "ֻ��$n������$v���һƬ����ʱ����$N��$w��\n",
        "$nʹ��̫��ȭ����ж���־���$v����һ�㣬$N��$w������������У���$n�����˺���\n",
        "$n����һ�࣬������$v����һ��$N��$w��$N��$wһ�¾�ƫ�˳�ȥ��\n",
});

string *unarmed_parry_msg = ({
        "����$n����һ�࣬����������һ��$N��$w��$N��$wһ�¾�ƫ�˳�ȥ��\n",
        "$n���������Ƴ�������$N��$w��Ȼ����������һ�࣬˳�ƺ�����$N�������һ�������У���$n�����˺���\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
