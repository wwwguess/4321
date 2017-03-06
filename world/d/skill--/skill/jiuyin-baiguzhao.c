//jiuyin-baiguzhao.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N��צ��Σ���צ������һ�С�������ǡ�ֱ����$n��$l",
    "force" : 320,
    "dodge" : 10,
    "damage": 30,
    "lvl"   : 0,
    "skill_name" : "�������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N˫��������צ��צצ����$n������������������$n��$lץ��",
    "force" : 380,
    "dodge" : 20,
    "damage": 45,
    "lvl"   : 20,
    "skill_name" : "��������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��ʹ�������޵�������$n��$l����ȫ������צӰ��",
    "force" : 440,
    "dodge" : 30,
    "damage": 55,
    "lvl"   : 40,
    "skill_name" : "���޵���" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$Nʹһ�С������ơ���˫צ�ó�����צӰץ��$nȫ��",
    "force" : 520,
    "dodge" : 40,
    "damage": 70,
    "lvl"   : 60,
    "skill_name" : "������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N����������һ�С�Ψ�Ҷ���˫צ������$n�������",
    "force" : 620,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������׹�צ������֡�\n");
    if ((int)me->query("max_force") < 200)
        return notify_fail("�������̫�����޷��������׹�צ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("jiuyin-baiguzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
        return notify_fail("������������������׹�צ��\n");
	me->receive_damage("kee", 30);
        me->add("force", -20);
	return 1;
}
void skill_improved(object me)
{
    tell_object(me, HIR "���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�\n" NOR );
    me->add("shen", -200);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		return HIR "��������������һ�����죬�����ǹ����������\n" NOR;
	}
}

