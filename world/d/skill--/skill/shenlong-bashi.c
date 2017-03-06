// shenlong-bashi ������ʽ
inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���Ӱ��б��,��������һĨ����$n��$l��ȥ",
	"damage" : 20,
	"parry": 10,
	"force": 100,
        "damage_type" : "����",
	"skill_name" : "��Ӱ��б"
]),
([	"action" : "$N�������,˫��ʹһ�С��嶡��ɽ��������$n��$l",
	"damage" : 30,
	"parry": 30,
    "damage_type" : "����",
	"skill_name" : "�嶡��ɽ"
]),
([	"action": "$N˳��ʹһ�С����в��ȡ����Ƽ�ת��,���ƻ���,����ֱ��$n",
	"damage" : 40,
	"dodge": 80,
	"parry": 20,
	"force": 200,
	"damage_type": "����",
	"skill_name" : "���в���"
]),
([	"action": "$N�˺󼸲�,ͻȻ����һ��,һ�С�������β�����ޱȹ���ػ���$n",
	"damage" : 50,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "������β"
]),
([	"action" : "$Nʹһʽ�������ơ���ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
	"damage" : 50,
	"force" : 250,
        "dodge" : 10,
	"lvl" : 30,
        "damage_type" : "����",
	"skill_name" : "������"
]),
([	"action": "$N����ʹ����Ǭ��������,����֧��,˫�ȷ�������$n",
	"damage" : 60,
	"dodge": -20,
	"parry": -20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "Ǭ������"
]),
([	"action": "$N���һ����ʹ����ͬ���ھ���������һ�а�����$n",
	"dodge": -25,
	"parry": -10,
	"damage" : 60,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "ͬ���ھ�"
]),
([	"action": "$N����һ����,�����ǳ���״,��Ȼ���Ǹ��°�ֱײ��$n",
	"dodge": 80,
	"damage" : 70,
	"parry": -10,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "���Ǹ���"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ʽ������֡�\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
		return notify_fail("��������ķ���򲻹����޷�ѧ������ʽ.\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ������ʽ��\n");
	if ((int)me->query("max_force") < 350)
		return notify_fail("�������̫�����޷���������ʽ��\n");
	if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("��������ķ���
�򲻹����޷�����ѧ������ʽ��\n");
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
		return notify_fail("�������������������ʽ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

