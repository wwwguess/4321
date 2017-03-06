// huagong-dafa.c ������
// by yucao
// modified by cleansword

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huagong-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��������ʲ�ᣡ\n");
	if ( me->query_skill("hunyuan-yiqi",1) 
	|| me->query_skill("huntian-qigong",1) 
       || me->query_skill("tianmo-dafa",1)
       || me->query_skill("huashan-neigong",1)
       || me->query_skill("zixia-shengong", 1)
	|| me->query_skill("taiji-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"huagong-dafa/" + func;
}

