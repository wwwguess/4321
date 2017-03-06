// lanhua-shou.c -������Ѩ��

inherit SKILL;

mapping *action = ({
([      "action" : "$N��ָ�ſ������μ����������$n��$l",
        "force" : 200,
        "dodge" : 30,
        "parry" : 30,
        "damage": 30,
        "lvl" : 100,
        "skill_name" : "�Խ�ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�������ָ���죬��������$n��$l",
        "force" : 180,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "lvl" : 60,
        "skill_name" : "��ָʽ",
        "damage_type" : "����"
]),
 ([      "action" : "$N��̬��ӯ��˫�ֺ�������������$n��$l��ȥ",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 15,
        "lvl" : 50,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ���Ʈ��������$n��$l",
        "force" : 100,
        "dodge" : 10,
        "parry" : 15,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N���ֺ����黨�����ֻ���Ʈ��$n��$l",
        "force" : 120,
        "dodge" : 30,
        "parry" : 20,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "�仨ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ΢�ţ�������˫������$n��$l��ȥ",
        "force" : 140,
        "dodge" : 10,
        "parry" : 5,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ַ��ɣ�ָ�˱ų�����������������$n��ȫ��",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "damage": 5,
        "lvl" : 20,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action" : "$N������Σ�����ƮƮ�����ֺ��Ʋ����������$n��$l",
        "force" : 80,
        "dodge" : 10,
        "parry" : 5,
        "damage": 0,
        "lvl" : 10,
        "skill_name" : "��Ҷʽ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������Ѩ�ֱ�����֡�\n");
        if ((int)me->query_skill("taohua-force", 1) < 15)
                return notify_fail("����һ��ڹ������������޷�ѧ������Ѩ�֡�\n");
        if ((int)me->query("max_force") < 70)
                return notify_fail("�������̫�����޷���������Ѩ�֡�\n");
        return 1;
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"lanhua-shou/" + action;
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
        level   = (int) me->query_skill("lanhua-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 20)
                return notify_fail("�������������������Ѩ�֡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
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
