// hunyuan-yiqi.c ���� ��Ԫһ����
// dts@xkx, cleansword@xkx

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("hunyuan-yiqi", 1);
	ns = (int)me->query("guilty");

        if ( me->query("gender") != "����" || me->query("is_married"))
		return notify_fail("���ͯ��֮�壬������ϰ��Ԫһ������\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������Ļ�Ԫһ������\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����Ԫһ������\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷���������Ļ�Ԫһ������\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("��Ԫһ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"hunyuan-yiqi/" + func;
}
