// tangshi-jian.c ��ʫ���� based on taiji-jian.c
// by tang

inherit SKILL;

mapping *action = ({
([	"action" : "$N�鲽������һ�С�������������������$w���������һ������$n��$l",
	"force" : 100,
	"dodge" : 40,
	"damage" : 25,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ���������������������$wʹ��һʽ�������ž��硹ֱ��$n��$l",
	"force" : 120,
	"dodge" : 35,
	"damage" : 30,
        "lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ֹ�����һ��$w��$wһ��Ϊ��������$n��$l",
	"force" : 140,
	"dodge" : 30,
	"damage" : 30,
        "lvl" : 10,
	"damage_type" : "����"
]),
([	"action" : "$N��̤���ԣ�һ�С����ɰ���ͼ����$wһ���$n��$l��ȥ��",
	"force" : 160,
	"dodge" : 25,
	"damage" : 35,
        "lvl" : 15,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ���������ɼ��ա���$nֻ������ǰ�����ʢ��$w��ס��ȫ��",
	"force" : 180,
	"dodge" : 20,
	"damage" : 35,
        "lvl" : 20,
	"damage_type" : "����"
]),
([	"action" : "$N������ת���ҽ���㣬����$w�������֣�����$w�������֣�һ�С���Ȫʯ������������$n��$l��",
	"force" : 200,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ǧɽ��ɾ�����$wƽ�ƣ���$n��ͷ����ȥ��",
	"force" : 220,
	"dodge" : 15,
	"damage" : 45,
        "lvl" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N���Ȱ�����һ�С��������𡹣�$w����������$n���Ȳ���",
	"force" : 240,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 35,
	"damage_type" : "����"
]),
([  "action" : "$N����š����������ָ��һ�С����������¡���$w������䣬����$n��$l��",
	"force" : 260,
	"dodge" : 15,
	"damage" : 55,
        "lvl" : 40,
	"damage_type" : "����"
]),
([	"action" : "$N����һ������һ�С����Ĺ���ʱ������������$w����$n��$l",
	"force" : 280,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 45,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һʽ���춹���Ϲ���������$w����$n��$l",
	"force" : 300,
	"dodge" : 10,
	"damage" : 65,
        "lvl" : 50,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���������֦����һ��$w��$w��Ϊ������â����$n��ͷ��������ȥ",
	"force" : 310,
	"dodge" : 10,
	"damage" : 70,
        "lvl" : 55,
	"damage_type" : "����"
]),
([	"action" : "$N�������ǣ�����$wһ�С��������Ǻ�������$n��$lбб��ȥ��",
	"force" : 320,
	"dodge" : 5,
	"damage" : 75,
        "lvl" : 60,
	"damage_type" : "����"
]),
([	"action" : "$N����$wʹ��������ҹ��������$n�͵ض�����ȥ",
	"force" : 330,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 65,
	"damage_type" : "����"
]),
([	"action" : "$N������ָ������΢̧������$wһ�С����粻�����ɱ㡹������$n��$l��",
	"force" : 340,
	"dodge" : 5,
	"damage" : 85,
        "lvl" : 70,
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ɨ��һ�С�ͭȸ���������ǡ������ֹ���$n��$l",
	"force" : 350,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 75,
	"damage_type" : "����"
]),
([	"action" : "$N����$w����һ�����ߣ������ĳ���һ�С���ʮ��������ҹ��������$n��$l",
	"force" : 360,
	"dodge" : -5,
	"damage" : 95,
        "lvl" : 80,
	"damage_type" : "����"
]),
([  "action" : "$N�����鱧��һ�С����˺δ��̴����$w�й�ֱ��������$n��$l",
	"force" : 370,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 85,
	"damage_type" : "����"
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("tangmen-xinfa", 1) < 20)
		return notify_fail("��������ķ����̫ǳ��\n");
        	if ((int)me->query_skill("tangmen-xinfa", 1) < (int)me->query_skill("tangshi-jian", 1) - 20 && (int)me->query_skill("literate", 1) < 250)
		return notify_fail("��������ķ������д�ֻ�򲻹����޷�������ʫ���������������.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tangshi-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("���������������ʫ������\n");
        	if ((int)me->query_skill("tangmen-xinfa", 1) < (int)me->query_skill("tangshi-jian", 1) - 20 && (int)me->query_skill("literate", 1) < 250)
                	return notify_fail("��������ķ������д�ֻ�򲻹����޷�������ʫ���������������.\n");
	me->receive_damage("kee", 30);
	return 1;
}

//string perform_action_file(string action)
//{
//	return __DIR__"taiji-jian/" + action;
//}

string *parry_msg = ({
        "ֻ��$n������$v���һƬ����ʱ����$N��$w��\n",
        "$nʹ����ʫ������ж���־���$v����һ�㣬$N��$w������������У���$n�����˺���\n",
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