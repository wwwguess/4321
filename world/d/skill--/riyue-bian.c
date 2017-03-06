// riyue-bian.c ���±޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N����������һ�С���ʯʽ��������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
	"dodge":		-10,
	"damage":		100,
	"lvl" : 0,
	"skill_name" : "��ʯʽ",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ�С��ϴ�ʽ��������$w��������ڿ�һ���͵���$n��ͷ����",
	"dodge":		-20,
	"damage":		200,
	"lvl" : 60,
	"skill_name" : "�ϴ�ʽ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С�����ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-40,
	"damage":		300,
	"lvl" : 90,
	"skill_name" : "����ʽ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С��ֺ�ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-50,
	"damage":		400,
	"lvl" : 100,
	"skill_name" : "�ֺ�ʽ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С��ѿ�ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-60,
	"damage":		500,
	"lvl" : 110,
	"skill_name" : "�ѿ�ʽ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С�������ա�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-60,
	"damage":		600,
	"lvl" : 120,
	"skill_name":  "�������",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С���շ�ħ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-70,
	"damage":		700,
	"lvl" : 130,
	"skill_name" : "��շ�ħ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С����ޱߡ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		100,
	"damage":		800,
	"lvl" : 200,
	"skill_name" : "���ޱ�",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_force") < 500 )
		return notify_fail("����������㣬û�а취�����±޷�, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

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
	level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("����������������±޷���\n");
	me->receive_damage("kee", 5);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
		return __DIR__"riyue-bian/" + action;
}

