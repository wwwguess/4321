// mantian-huayu.c ���컨��
#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage == "throwing"; }

int valid_learn(object me)
// need more limit here
{
	if ((int)me->query_skill("throwing", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
	return 1;
}
                                                             
int practice_skill(object me)
{
	if ((int)me->query("kee") < 50)
		return notify_fail("����������������컨�ꡣ\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"mantian-huayu/" + action;
} 