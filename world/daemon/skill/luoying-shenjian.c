// luoying-shenjian.c ��Ӣ��

#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "name":         "��Ӣ�ͷ�",
        "action":       "$Nʹһ�С���Ӣ�ͷס�����������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l",
        "force":        100,
		"parry":        5,
        "damage":       40,
		"damage_type":	"����"
	]),
    ([  "name":         "�����һ�",
        "action":       "$N�趯$w��һʽ�������һ�����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l",
        "force":        140,
        "parry":        -20,
        "damage":       50,
        "damage_type":  "����"
    ]),
    ([  "name":         "��������",
        "action":       "$N������$nһת������$w����һָ��һʽ���������꡹�ó����콣Ӱ����$n$l�����ӳ�����",
        "force":        180,
		"dodge":        10,
        "damage":       70,
		"damage_type":	"����"
	]),
    ([  "name":         "���Ƿɻ�",
        "action":       "$N����ƮȻ�����ڰ��������һ������Ȼһʽ�����Ƿɻ�������$w�������޵�������$n��$l",
        "force":        210,
		"dodge":		-10,
        "damage":       120,
		"damage_type":	"����"
	]),
    ([  "name":         "������",
        "action":       "$N�������࣬һʽ��ϸ���ɷ��ء�ͷ�½��ϣ�һ�С������䡹����$w���һ����������$n��$l",
        "force":        240,
        "dodge":        10,
        "damage":       120,
	"damage_type":	"����"
    ]),
    ([  "name":         "���컨��",
        "action":       "$Nһ�����ʹ�������컨�꡹������$w�ó����컨�꣬Ѹ����������$n��$l",
        "force":        280,
        "dodge":        15,
        "damage":       140,
	"damage_type":	"����"
    ]),
    ([  "name":         "�仨����",
        "action":       "$N��̾һ��������$w����һ����һʱ���仨���⡹��$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
        "force":        320,
        "dodge":        0,
        "damage":       140,
	"damage_type":	"����"
    ]),

});

int valid_learn(object me)
{
	object ob;

    if( (int)me->query_skill("bibo-shengong",1) < 30)
        return notify_fail("��ı̲��񹦻�򻹲�����\n");

    if( (int)me->query("max_force") < 100 )
        return notify_fail("���������������������Ӣ�񽣡�\n");

	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ�����ѧϰ������\n");

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

    if( (int)me->query("kee") < 30
    ||  (int)me->query("force") < 5 )
        return notify_fail("�����������������û�а취��ϰ��Ӣ�񽣡�\n");

	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ�����ϰ��������\n");

    me->receive_damage("kee", 30);
	me->add("force", -5);
    write("�㰴����ѧ����һ����Ӣ�񽣡�\n");
	return 1;
}

