// tianmo-dafa.c ��ħ��
// dfbb@hero

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷������ħ�󷨡�\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail(" ��ħ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianmo-dafa/" + func;
}

int help(object me)
{
        write(@HELP
	��ħ����������̵�ʮһ�����������֮������
	�����ֿ�,������,�Ǳ��̵Ļ����ķ�.
	����������ܾ��ǿ�����ħ����(jie ti)
	������������ʱ, ʩ�н���󷨺���Ȼ��Ԫ������
	ȴ�ܴ������ս��.ֻ��ʱЧ����
HELP
        );
        return 1;
}

