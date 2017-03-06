// hanbing-zhang.c

inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "dodge": 30,
        "force": 440,
//      "poison": 80,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "dodge": 10,
        "force": 370,
//      "poison": 60,
        "damage_type": "����"
]),
([	"action": "$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
	"dodge": -20,
	"force": 230,
//      "poison": 100,
	"damage_type": "����"
]),
([	"action": "$N˫��Ю��һ���ȳ�֮������$n��$l",
	"dodge": 10,
	"force": 300,
//      "poison": 80
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

mapping query_action(object me)
{
        if (random(me->query_skill("strike")) > 60 &&
            me->query_skill("force") > 50 &&
            me->query("force") > 100 ) {
                me->add("force", -100);
                return ([
                "action": "$Nҧ����⣬������Ѫ���ۼ�ȫ������������$n",
                "force": 300,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("��Ļ����󷨻�򲻹����޷����������ơ�\n");
	if ((int)me->query("max_force") < 60)
		return notify_fail("�������̫�����޷�����������");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 8)
		return notify_fail("��������������������ơ�\n");
	if (me->query_skill("hanbing-zhang", 1) < 50)
		me->receive_damage("kee", 20);
	else
		me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("huagong-dafa")) > 10 ) 
	{
	victim->apply_condition("ice_poison", random(me->query_skill("huagong-dafa")/10) + 1 +
	victim->query_condition("ice_poison"));
	}
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-zhang/" + action;
}
