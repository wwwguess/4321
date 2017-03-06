// ������

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("yunlong-xinfa", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("yunlong-shengong", 1);

	if ( me->query("gender") == "����" && nh > 49)
		return notify_fail("���޸����ԣ���������������������������񹦡�\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������������񹦡�\n");

	if ( nf < 40)
		return notify_fail("��Ļ����ڹ���򻹲������޷���������񹦡�\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
//	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunlong-shengong/" + func;
}
