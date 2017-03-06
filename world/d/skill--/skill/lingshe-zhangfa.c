//lingshe_zhangfa.c �����ȷ�

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����߳�����������$w�󿪴���ɨ��$n��$l",
	"force" : 100,
	"dodge": -3,
	"damage": 18,
	"lvl" : 10,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ�С�ҡͷ��β����$n��$l��ȥ",
	"force" : 140,
	"dodge": -5,
	"damage": 24,
	"lvl" : 20,
	"skill_name" : "ҡͷ��β",
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С������½�������$n��$l",
	"force" : 180,
	"dodge": -10,
	"damage": 30,
	"lvl" : 30,
	"skill_name" : "�����½�",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�����ͦ��������$w����ɨ��$n��$l",
	"force" : 220,
	"dodge": -5,
	"damage": 36,
	"lvl" : 40,
	"skill_name" : "����ͦ��",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ�С��������ߡ���$w�����ػ���$n��$lɨȥ",
	"force" : 260,
	"dodge": -3,
	"damage": 42,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([	"action": "$N����$wһ�ӣ�ʹ��һ�С��߲����ҡ����������ɨ��$n��$l",
	"force" : 300,
	"dodge": -5,
	"damage": 48,
	"lvl" : 60,
	"skill_name" : "�߲�����",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ�С�������ɽ�����߾�����$w����ͷ����$n��$l",
	"force" : 340,
	"dodge": -10,
	"damage": 54,
	"lvl" : 80,
	"skill_name" : "������ɽ",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ�С����߳�����������$w��һ̽��ֱɨ$n��$l",
	"force" : 380,
	"dodge": -3,
	"damage": 60,
	"lvl" : 100,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),

});

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
	level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//	return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 70)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("������������������ȷ���\n");
	me->receive_damage("kee", 20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hamagong")) > 10 ) 
	{
	victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
	victim->query_condition("snake_poison"));
        tell_object(victim, HIG "����ñ����еĵط�һ����ľ��\n" NOR );
        tell_object(victim, HIG "ԭ���Ǳ���ͷ�ܳ��Ķ���ҧ��һ�ڣ�\n" NOR );
	}
}
