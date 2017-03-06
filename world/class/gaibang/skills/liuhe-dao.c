//liuhe-dao.c -���ϵ�

inherit SKILL;

mapping *action = ({
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��������ҡ�������һ������ն��$n",
        "force" : 140,
        "dodge" : -5,
        "damage" : 15,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ͺ���������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "skill_name" : "�ͺ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С�����޳�����˫�ֳ����������У�����$n���ؿ�",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "skill_name" : "����޳�",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С����է�ϡ����������ã����ҿ�����������$n",
        "force" : 210,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "skill_name" : "���է��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����Ǻ�ɽ�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "skill_name" : "���Ǻ�ɽ",
        "damage_type" : "����"
]),
([      "action" : "$N����פ�أ�һ�С��Ǳ����졹���ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "skill_name" : "�Ǳ�����",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="dagou-bang"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 10)
                return notify_fail("��Ļ����������̫ǳ��\n");
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
        level   = (int) me->query_skill("liuhe-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("����������������ϵ���\n");
        me->receive_damage("kee", 25);
        return 1;
}

string *parry_msg = ({
        "$n�����е�$v����$N����ָ��\n",
        "$n���̤ǰһ�������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
        "$n���е�$vһ�������һƬ����������$N��ȫ��\n",
        "$n΢��һ�������е�$v����һ���⻡����$N��ȫ��Χס��\n",
	"$n���е�$vһ����ֱ��$N��\n",
	"$n���е�$v������$N��ȫ��Χס��\n",
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
