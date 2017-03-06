// shenghuolin.c
// Writed by yuer

inherit SKILL;

mapping *action = ({
([      "action":"$N����һ�Σ���ž����һ����ץס$n�ĺ��죬ԶԶ���˳�ȥ.",
        "force" : 120,
        "dodge" : -10,
        "damage": 35,
        "lvl" : 0,
               "weapon" : "��������",
        "damage_type":  "����"
]),
([      "action":"$N$w��$n�ʺ��ȥ��$w��Ȼβ��һ��������$n����",
        "force" : 140,
        "dodge" : -10,
        "damage": 50,
        "lvl" : 10,
		"weapon" : "����",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ�������������Ӱһ��,����һ��������$w��$n���ػ�ȥ��",
        "force" : 160,
        "dodge" : 5,
        "damage": 75,
        "lvl" : 25,
		"weapon" : "��������",
        "damage_type":  "����"
]),
([      "action":"ͻȻ��$N���ˤ����$w��һ������˼��ĽǶȵ�㼱����$n��",
        "force" : 200,
       "dodge" : 5,
        "damage": 100,
        "lvl" : 40,
	"weapon" : "��ָ",
        "damage_type":  "����"
]),
([      "action":"$N���弱ת�������������ţ�$w�������$n��С�����˵����������ף�����˼��",
        "force" : 260,
       "dodge" : 5,
        "damage": 115,
        "lvl" : 55,
		"weapon" : "��ָ",
        "damage_type":  "����"
]),
([      "action":"$n����$N��$l��$N���˷�������Ȼ��ͷ��$nײ��������$nһ�����ֲ���",
        "force" : 270,
       "dodge" : 5,
        "damage": 150,
        "lvl" : 70,
		"weapon" : "����",
        "damage_type":  "����"
]),
([      "action":"$NԾ���գ���Ȼ��$nͷ���������������ǹ��죬�����β����ˡ�",
        "force" : 370,
       "dodge" : 5,
        "damage": 170,
        "lvl" : 80,
		"weapon" : "",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "strike" || usage == "parry"; 
}
int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("��ľ����񹦻��̫ǳ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("shenghuo-shengong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_practice(object me)
{
        return notify_fail("ʥ���񹦲������ķ�ʽ��\n");
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-shengong/" + action;
}
string *parry_msg = ({
        "ֻ��$n������$v���һƬ����ʱ����$N��$w��\n",
        "$n����һ�࣬������$v����һ��$N��$w��$N��$wһ�¾�ƫ�˳�ȥ��\n",
});

string *unarmed_parry_msg = ({
        "����$n����һ�࣬����������һ��$N��$w��$N��$wһ�¾�ƫ�˳�ȥ��\n",
        "$n���������Ƴ�������$N��$w��Ȼ�����һ������������һ�࣬�ܹ��˹�����\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


