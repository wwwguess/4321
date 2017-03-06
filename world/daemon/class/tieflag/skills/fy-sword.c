
// fy-sword.c
//written by kouga
inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nʹ��һ�С��������ա������е�$w����һ��Բ������$n��$l����",
                "dodge":                100,
		"parry":		-30,
                "damage":               150,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���������ĳ�һ�ƣ������е�$wʹ��һ�С��һ����ơ���ն��$n��$l",
                "dodge":                -40,
		"parry":		150,
                "damage":               270,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�ˮ�����ɡ�������������ˮ������$w���������ն��$n��$l",
                "dodge":                50,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һʽ�ġ������ķ�����׼$n��$l�̳�һ��",
                "dodge":                200,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$w���μ������У�һ�С�����������$n��ȥ",
                "dodge":                160,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫���ս���ʹ��һ�С���Ŀ�ѻԡ�����$n��$l",
                "dodge":                -100,
		"parry":		300,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���н�����һ�Σ�$w��Ϊһ����⣬ʹ����������ġ�����$n��$l",
                "dodge":                200,
		"parry":		200,
                "damage":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취��������ƽ�����\n");

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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return  notify_fail("�����������������û�а취��ϰ������ƽ�����\n"
);
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�������ƽ�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("tieflag") + "/fy-sword/" + action;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С�ɽ�����ܡ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
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
        return -10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}