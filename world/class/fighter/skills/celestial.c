// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50 )
		return notify_fail("���ɱ���������޷�������������а��\��\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��а��\ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return CLASS_D("fighter") + "/celestial/" + func;
}

