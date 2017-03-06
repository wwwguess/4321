// zhuifeng-liushi.c ׷����ʽ

inherit SKILL;

mapping *action = ({
([	"action" : "$nһ�С��·�һ�㡹������һԾ��Ʈ����� ��ת�ۼ���Ƶ���$N�����\n",
	"dodge"  : 20
]),
([	"action" : "$nһ�С��������¡���ȫ���ֱ���εض���\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ����������Ϫ�ס������μ��ζ���\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
	"dodge"  : 80
]),
([	"action" : "$nһʽ������ˮӰ��������ȥ���ڰ����һת�����䵽����Զ�ĵط���\n",
	"dodge"  : 100
]),
([	"action" : "$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
	"dodge"  : 120
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("zhuifeng-liushi");

	if (level < 60 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("�������̫���ˣ�������׷����ʽ��\n");
	me->receive_damage("kee", 30);
	return 1;
}
