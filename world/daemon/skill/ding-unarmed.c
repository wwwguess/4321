// ding-unarmed.c һ��һ��ȭ
inherit SKILL;

mapping *action = ({
([	"action" : "$N��������һĨ����$n��$l��ȥ",
	"damage" : 180,
        "damage_type" : "����"
]),
([	"action" : "$N����һ�ᣬ����$n��$l",
	"damage" : 220,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������һ��һ��ȭ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

