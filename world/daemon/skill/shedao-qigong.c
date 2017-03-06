// shedao-qigong  �ߵ��湦
inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С��ɺ����᡹����$wһ�ᣬ����$n��$l",
	"damage" : 40,
	"parry": 40,
	"force": 150,
	"damage_type" : "����",
	"skill_name" : "�ɺ�����"
]),
([	"action": "$Nʹ�������߳�����������΢��,����$wٿ����$n��$l��ȥ",
	"damage" : 50,
	"dodge": 80,
	"parry": 10,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "���߳���"
]),
([	"action": "$N����΢��,���㷴��,����ת��,ʹһ�С�����������������$w�Ѵ���$n$l",
	"damage" : 60,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ��������衹��������$n, ����һ��,˳����$w��һ��,$w��Ȼ���Լ��ʺ���.����$N��������һ��,$w�ӹ����ʺ�,����$n�������",
	"damage" : 70,
	"force" : 350,
        "dodge" : 50,
	"lvl" : 40,
        "damage_type" : "����",
	"skill_name" : "�������"
]),
([	"action": "$N�����ڵ���һ���,ʹһ�С�С����¡�,��$n�������,����$wֱ��$n",
	"damage" : 80,
	"dodge": 70,
	"parry": 30,
	"force": 350,
	"damage_type": "����",
	"skill_name" : "С�����"
]),
([	"action": "$N���һ����ʹһ�С�����ٶ�������������$n��ȪҪѨ,����$nˤ���ڵ�",
	"dodge": -25,
	"parry": -10,
	"damage" : 70,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "����ٶ�"
]),
([	"action": "$N˫��һ��,�������,һ�С�³�ﲦ��������ץ��$n�ҽ�����,����$wֱ��$nС��",
	"dodge": 80,
	"damage" : 80,
	"parry": -10,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "³�ﲦ��"
]),
([	"action": "$NͻȻһ�������,һ�С����ཱུ����,˫��һ��,���ڼ�ͷ,˫��ֱ��$n",
	"dodge": 90,
	"damage" : 90,
	"parry": 30,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "���ཱུ��"
]),
});

int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
		return notify_fail("��������ķ���򲻹����޷�ѧ�ߵ��湦.\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�ߵ��湦��\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 50)
		return notify_fail("���������ʽ��򲻹����޷�ѧ�ߵ��湦��\n");
	if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
		return notify_fail("��������ķ���
�򲻹����޷�����ѧ�ߵ��湦��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 30)
		return notify_fail("��������������ߵ��湦��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shedao-qigong/" + action;
}
