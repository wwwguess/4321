// tangmen-xinfa.c �����ķ�

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}


/*string exert_function_file(string func)
{
        return __DIR__"tangmen-xinfa/" + func;
} */