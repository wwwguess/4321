// liuh-ken.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$Nʹһ�С���������¡�����׼$n��$l��ƮƮ����ȥ",
                "dodge":                -50,
                "parry":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������ƣ�����һ�Σ�һ�С��ᵱ�����������$n��$l��ȥ",
                "dodge":                -20,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ��������أ�����һ�С���ħʽ����$n��$l����",
                "dodge":                -100,
                "parry":                -80,
                "force":                 -60,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����΢�գ�����һתʹ��һ�С����³���ɽ����ץ��$n��$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$Nٿ��һ��ת��˫��һ�����ƾ����桹ֱ��$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ��������ƮƮ���溬ɱ����ʹ������ħʽ������$n$l",
                "dodge":                -110,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������$n$l���������һ�С��׺������������Ѹ�����",
                "parry":                -50,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�����ƽ�ƣ�һ�С���ӿ����������$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("��ħħ�Ʒ�������֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="strike" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$nһ�С���ã�ƺ��䡹���������$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n������ϣ����ơ�ժ��ɨ�¡����Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�б��С¥���Գ������$N��$w������\n",
        "$nһ�С����ս�ħ��������һ��$N��$w���֣���ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С���ɽʽ�����Ƶ�$N��;���С�\n",
        "$n����������һ�С��ƺ��뺣������$N֮�ؾȡ�\n",
        "$n����ѹ�£�����һ�С���ħʽ������$N���ڳ��⡣\n",
        "$n˫�������ʹ��һ�С��׺���������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}
