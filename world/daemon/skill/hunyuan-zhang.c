// hunyuan-zhang.c -��Ԫ��

inherit SKILL;

mapping *action = ({
([      "action" : "$N���Ʊ�������һ������һʽ���������졹��˫�Ƽ�����$n�ļ�ͷ",
        "force" : 350,
        "dodge" : 15,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С����Ƴ�ᶡ���˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 50,
        "dodge" : 30,
        "skill_name" : "���Ƴ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ��Ѩ",
        "force" : 30,
        "dodge" : 25,
        "skill_name" : "�׺����",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n��$l",
        "force" : 30,
        "dodge" : 20,
        "skill_name" : "�ƶ�����",
        "damage_type" : "����"
]),
([       "action" : "$N�����黮������һ�ǡ����ɴ�䡹����$n��$l",
        "force" : 30,
        "dodge" : 15,
        "skill_name" : "���ɴ��",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����������������ֻ���$n��$l�����ֹ���$n���ɲ�",
        "force" : 30,
        "dodge" : 10,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��Խ��һ�С��ޱ���ľ������$n��$l��ȥ",
        "force" : 30,
        "dodge" : 25,
        "skill_name" : "�ޱ���ľ",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ȭ�����һ����һʽ����ɽ��ˮ����������$n��$l",
        "force" : 40,
        "dodge" : 20,
        "skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ���ȭ�����󷢣�һʽ���������á�����������$n��$l",
        "force" : 50,
        "dodge" : 15,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֿ��裬ʹ����������ơ�����$n��$l��ȥ",
        "force" : 30,
        "dodge" : 15,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="poyu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ԫ�Ʊ�����֡�\n");
        if ((int)me->query_skill("huashan-neigong", 1) < 20 && (int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("����ڹ��ȼ��������޷�ѧ��Ԫ�ơ�\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
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
        level   = (int) me->query_skill("hunyuan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 20)
                return notify_fail("���������������Ԫ�ơ�\n");
        me->receive_damage("kee", 25);
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
