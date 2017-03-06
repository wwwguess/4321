// moqin.c

inherit SKILL;

mapping *array_action= ({
		([		"action":
"$N1��$w1���϶��£�$N2��$w2���¶��ϣ������һ������������$n��$l",
				"dodge":		300,
				"parry":		300,
				"damage":		900,
				"damage_type":	"����",
		]),
});
mapping *action = ({
        ([      "action":               
"$N�������������ġ��������缱��һ�����$n��$l",
                "dodge":                -20,
                "damage":               900,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��ħ�����еġ������ҡ��������糱ˮ��ӿ��$n��$l",
                "dodge":                -20,
                "damage":               900,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�������������ҡ������罣����$n��$l",
                "dodge":                20,
                "damage":               900,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("�������������û�а취���١�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "music" )
                return notify_fail("���������һ���ٲ�����ħ���񹦡�\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="music") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
mapping query_array_action(object me, object weapon)
{
        return array_action[random(sizeof(array_action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 300
        ||      (int)me->query("force") < 300 )
                return 
notify_fail("�����������������û�а취���١�\n");
        me->receive_damage("kee", 300);
        me->add("force", -3);
        write("�㰴����ѧ����һ���١�\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/music/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n���������ٷ�к����������һ��ǽ������$N��$w��\n",
        "$n��������������������$N��$w�������⡣\n",
        "$n��������ϼ���졹����������������գ�������$N��$w��\n",
        "$n���е�$v�������ϱ��ҡ���һ���׹���$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����ܲ�͸�磬������������������ס��$N�Ĺ��ơ�\n",
        "$n�����������ҡ�����������ʧ��һ�����С�\n",
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

