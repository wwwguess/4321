// shexing-shou.c -���ε���

inherit SKILL;

mapping *action = ({
([      "action" : "$N�ڿշ���һʽ��������ӿ����˫��˫���������$n�޿ɶ��",
        "force" : 200,
        "dodge" : 30,
        "parry" : 30,
        "damage": 30,
        "lvl" : 100,
        "skill_name" : "������ӿ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�һʽ����ܰ���񡹣�����$n��$l��ȥ",
        "force" : 180,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
 ([      "action" : "$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 15,
        "lvl" : 50,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫ȭ���裬һʽ��������ܡ�������һ�Σ���Ʈ��������$n��$l",
        "force" : 100,
        "dodge" : 10,
        "parry" : 15,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N���ֺ��ƾٱ���һʽ��������Ӱ�������ֻ�������$n��$l",
        "force" : 120,
        "dodge" : 30,
        "parry" : 20,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "������Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ������һʽ���������㡹������$n��$l��ȥ",
        "force" : 140,
        "dodge" : 10,
        "parry" : 5,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ����ͷ��β����������Σ������͵ز���$n��$l",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "damage": 5,
        "lvl" : 20,
        "skill_name" : "��ͷ��β",
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ����һʽ�����߳�������ֱȡ$n��$l",
        "force" : 80,
        "dodge" : 10,
        "parry" : 5,
        "damage": 0,
        "lvl" : 10,
        "skill_name" : "���߳���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="xianglong-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ε��ֱ�����֡�\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 10)
                return notify_fail("��Ļ���������򲻹����޷�ѧ���ε��֡�\n");
        if ((int)me->query("max_force") < 50)
                return notify_fail("�������̫�����޷������ε��֡�\n");
        return 1;
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
        level   = (int) me->query_skill("shexing-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 20)
                return notify_fail("����������������ε��֡�\n");
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
