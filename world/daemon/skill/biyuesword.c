
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С�ƮƮ���ľ��ɷ塹������$w��һ��һ�����$n��$l",
                "dodge":                -20,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����½��еġ���ϸ���������⡹����������հ�����$n��$l",
                "dodge":                -20,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�ָ�������ǽ��С�������$wĬĬ������$n��$l",
                "dodge":                -30,
                "damage":               80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһʽ���������޺�Ѱ�١���׼$n��$lһ���̳��߽�",
                "damage":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�Ϊ�������ɴǳ������$n��$l",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С�С�ϴ�������Ũ�����ֶ�׼$n$lһ����ȥ",
                "dodge":                -20,
                "damage":               70,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����½�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return 
notify_fail("�����������������û�а취��ϰ���½�����\n");
        me->receive_damage("kee", 50);
        me->add("force", -5);
        write("�㰴����ѧ����һ����½�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/deisword/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С������ٷ�����Զ�������е�$v������$N��$w��\n",
        "$nʹ�����ؿ��ŵ�ٻ��ԡ�����$N��$w�������⡣\n",
        "$nʹ��һ�С���Ƶ����ܺ��ߡ������е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ�С����ս���֪���򡹣���$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬һ�С�����ɺ��ϧδ�ա���ס��$N�Ĺ��ơ�\n",
        "$n����һ�С������Դ�������������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�״Ԫ���������Ρ���$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ���С�һ֦�����϶��򡹣��ȵ�$N�������ˡ�\n",
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
	return 20;
}

