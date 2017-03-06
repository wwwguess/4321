
// tangmen-duzhang.c, based on xingxiu-duzhang.c
// by tang

inherit SKILL;

mapping *action = ({
([      "action": "$Nһ�С�������¥����������ǰ�������ں���$n��$l��ȥ",
        "dodge": 30,
        "force": 160,
//      "poison": 80,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��һ�С�������Ӱ��˫�Ʒ���������$n��$l",
        "dodge": 10,
        "force": 160,
//      "poison": 60,
        "damage_type": "����"
]),
([	"action": "$N�������������֣�һ�С���ӥ���á������ޱȵ�ץ��$n��$l",
	"dodge": -20,
	"force": 150,
//      "poison": 100,
	"damage_type": "����"
]),
([	"action": "$N���һ��������̤ѩѰ÷��������������$n��ǰһ�Σ�����Ю��һ���ȳ�֮������$n��$l",
	"dodge": 10,
	"force": 160,
//      "poison": 80
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ; }

mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 60 &&
            me->query_skill("dugong") > 50 &&
            me->query("force") > 100 ) {
                me->add("force", -100);
                return ([
                "action": "$Nҧ����⣬������Ѫ���ۼ�ȫ��Ķ��ʻ���$n",
                "force": 300,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����Ŷ��Ʊ�����֡�\n");
	if ((int)me->query_skill("dugong", 1) < 10)
		return notify_fail("��Ķ�����򲻹����޷������Ŷ��ơ�\n");
	if ((int)me->query("max_force") < 60)
		return notify_fail("�������̫�����޷������Ŷ���");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 8)
		return notify_fail("����������������Ŷ��ơ�\n");
	if (me->query_skill("tangmen-duzhang", 1) < 50)
		me->receive_damage("kee", 20);
	else
		me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
                //if( random(me->query_skill("huagong-dafa")) > (damage_bonus + foo)/3 )
	if( random(me->query_skill("tangmen-duzhang")) > 5) {
		//victim->receive_wound("kee", (damage_bonus + foo));
		victim->apply_condition("tm_poison", random(2) + 1 +
			victim->query_condition("tm_poison"));
	}
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
