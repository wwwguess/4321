// xianglong-zhang.c ����ʮ����
// modified by king  ԽսԽ�£� 97.05

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"force": 130,
	"damage_type": "����"
]),
([	"action": "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
	"dodge": -10,
	"parry": -10,
	"force": 150,
	"damage_type": "����"
]),
([	"action": "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "dodge": -15,
	"parry": -10,
	"force": 170,
	"damage_type": "����"
]),
([	"action": "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 190,
	"damage_type": "����"
]),
([	"action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
	"dodge": -15,
	"parry": -20,
	"force": 210,
	"damage_type": "����"
]),
([	"action": "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
	"dodge": -10,
	"parry": 10,
	"force": 220,
	"damage_type": "����"
]),
([	"action": "$Nʹ��������ެ����˫���������ϻ���$n��$l",
	"dodge": -15,
	"parry": 40,
	"force": 230,
	"damage_type": "����"
]),
([	"action": "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",
	"dodge": -15,
	"parry": 20,
	"force": 240,
	"damage_type": "����"
]),
([	"action": "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",
	"dodge": -10,
	"parry": 40,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ������$n��$l��������",
	"dodge": -20,
	"parry": -20,
	"force": 260,
	"damage_type": "����"
]),
([	"action": "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 270,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",
	"dodge": -20,
	"parry": 30,
	"force": 280,
	"damage_type": "����"
]),
([	"action": "$N˫������ʹ����ʱ����������$n��������",
	"dodge": -20,
	"parry": 20,
	"force": 300,
	"damage_type": "����"
]),
([	"action": "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
	"dodge": -25,
	"parry": -10,
	"force": 330,
	"damage_type": "����"
]),
([	"action": "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
	"dodge": -25,
	"parry": 1,
	"force": 350,
	"damage_type": "����"
]),
([	"action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",
	"dodge": -20,
	"parry": 40,
	"force": 360,
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������ڡ���˫�������������$n��$l",
	"dodge": -25,
	"parry": 10,
	"force": 380,
	"damage_type": "����"
]),
([	"action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
	"dodge": -30,
	"parry": 10,
//	"damage": 40,
	"force": 450,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʮ���Ʊ�����֡�\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	if( (int)me->query_temp("xianglong") && ( (int)me->query("force") > 20 ) )
	{
		me->add_temp("str", (int)me->query_temp("str_count"));
		me->add("force", -20);
		me->add_temp("str_no", 1);
		me->add_temp("display_no", 1);
		if( (int)me->query_temp("display_no") == 2 )
		{
		message_vision( HIR"\n$N������һ������ԽսԽ�£�\n"NOR, me);
		me->set_temp("display_no", 0);
		}
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 10)
		return notify_fail("�����������������ʮ���ơ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xianglong-zhang/" + action;
}

