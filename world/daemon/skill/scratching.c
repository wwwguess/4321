
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "�������",
                "action":               "$Nһ�С�������桹������$w���𼸸�����������$n��$l",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ʿ����",
                "action":               "$N����һ�䣬һ�С���ʿ���ӡ���$w����$n��$l",
                "dodge":                -50,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���˺�һ",
                "action":               "$N�Ӷ�$w��һ�С����˺�һ��Ю����������Ϯ��$n��$l",
                "dodge":                -40,
		"damage":		50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "Ⱥħ����",
                "action":               "$N����$wһ�գ�ʹ����Ⱥħ���ס���$n��$l��ݺݵĿ�ȥ",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����Ϲ�",
                "action":               "$Nһ�С������Ϲء���$wһ�������Ữ��$n$l",
                "dodge":                -60,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "Ǭ��һ��",
                "action":               "$N����һ���û���һ���⻪��һ�С�Ǭ��һ��������$n",
                "dodge":                50,
                "damage":               150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 80 )
                return notify_fail("�������������û�а취����ʦ������\n");

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
        object ob;

	if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ��ʦ������\
");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����ʦ������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


