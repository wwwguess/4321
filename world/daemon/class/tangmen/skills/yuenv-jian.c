// yuenv-jian.c ԽŮ���� based on taiji-jian.c
// by tang

inherit SKILL;

mapping *action = ({
([	"action" : "$N�����ֱۣ�һ�С���ŮͶ�󡹣�����$w��$n��$l��ȥ",
	"force" : 100,
	"dodge" : 30,
	"damage" : 30,
        "lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�һЦ��ǡ���$wһ���$n��$l��ȥ��",
	"force" : 130,
	"dodge" : 25,
	"damage" : 40,
        "lvl" : 15,
	"damage_type" : "����"
]),
([	"action" : "$N����$w��㣬һ�С���Ц�����������$n��$l��",
	"force" : 160,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��Ĺȼ��ˡ���$w����������$n�ĸ�����",
	"force" : 190,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 35,
	"damage_type" : "����"
]),
([	"action" : "$N����$w���������һ�С����������������$n��$l",
	"force" : 220,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 45,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������������$wһ������$n��$l��ȥ",
	"force" : 250,
	"dodge" : 5,
	"damage" : 70,
        "lvl" : 55,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һ�С����ձ�������$w��$n�ľ���Ĩȥ",
	"force" : 280,
	"dodge" : -5,
	"damage" : 80,
        "lvl" : 65,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ġ���$w�س飬������$n��$l��ȥ",
	"force" : 310,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 75,
	"damage_type" : "����"
]),
([  "action" : "$N����Ծ��$w����һ��������һ�С�������졹����$n��ͷ����",
	"force" : 340,
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
	if ((int)me->query_skill("sunv-xinfa", 1) < 20)
		return notify_fail("�����Ů�ķ����̫ǳ��\n");
        	if ((int)me->query_skill("sunv-xinfa", 1) < (int)me->query_skill("yuenv-jian", 1) - 20 && (int)me->query_skill("sunv-xinfa", 1) < 200)
		return notify_fail("�����Ů�ķ���򲻹����޷�����ԽŮ���������������.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("yuenv-jian",1);
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
		return notify_fail("�������������ԽŮ������\n");
        	if ((int)me->query_skill("sunv-xinfa", 1) < (int)me->query_skill("yuenv-jian", 1) - 100 && (int)me->query_skill("literate", 1) < 250)
                	return notify_fail("�����Ů�ķ������д�ֻ�򲻹����޷�����ԽŮ���������������.\n");
	me->receive_damage("kee", 30);
	return 1;
}

string *parry_msg = ({
        "ֻ��$n������$v���һƬ����ʱ����$N��$w��\n",
        "$nʹ��ԽŮ������ж���־���$v����һ�㣬$N��$w������������У���$n�����˺���\n",
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