// lotusforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism") < (int)me->query_skill("lotusforce") )
		return notify_fail("��Ĵ�˷���Ϊ�������޷���������������ķ���\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bonze") + "/lotusforce/" + func;
}
