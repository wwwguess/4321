// yunlong-bian.c �����޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N����һ�һ�С�����ٵء�������$w���ñ�ֱ����׼$n��ͷ����",
	"force":		100,
	"dodge":		10,
	"damage":		10,
	"lvl" : 0,
	"skill_name" : "����ٵ�",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ�С������ĺ���������$w��������ڿ�һ���͵ػ���$n̫��Ѩ",
	"force":		150,
	"dodge":		10,
	"damage":		20,
	"lvl" : 10,
	"skill_name" : "�����ĺ�",
	"damage_type":	"����"
]),
([	"action":		"$N৵�һ�����ޣ�һ�С�������ˮ��������$w���ñ�ֱ������$n˫��",
	"force":		200,
	"dodge":		30,
	"damage":		30,
	"lvl" : 20,
	"skill_name" : "������ˮ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С����Ƽ��ա�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"force":		200,
	"dodge":		40,
	"damage":		40,
	"lvl" : 30,
	"skill_name" : "���Ƽ���",
	"damage_type":	"����"
]),
([	"action":		"$N��������һ�С���ɽ��ʯ��������$w��һ��ͭ����ֱ����$n",
	"force":		250,
	"dodge":		50,
	"damage":		50,
	"lvl" : 40,
	"skill_name" : "��ɽ��ʯ",
	"damage_type":	"����"
]),
([	"action":		"$N����һ�ӣ�һ�С����Χ����������$wֱ����$n����",
	"force":		300,
	"dodge":		-20,
	"damage":		60,
	"lvl" : 50,
	"skill_name" : "���Χ��",
	"damage_type":	"����"
]),
([	"action":		"$N�߸�Ծ��һ�С���Į���̡�������$w��ֱ��$n��ͷ����",
	"force":		350,
	"dodge":		-50,
	"damage":		70,
	"lvl" : 60,
	"skill_name" : "��Į����",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_force") < 200 )
		return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");

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
	level   = (int) me->query_skill("yunlong-bian",1);
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
		return notify_fail("������������������޷���\n");
	me->receive_damage("kee", 5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-bian/" + action;
}
