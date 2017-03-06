// jiuyang-shengong.c ������
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ( (me->query("family/family_name") != "������"))
		return notify_fail("�����񹦲�����, �����ֵ��Ӳ���!\n");
				    
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beimin-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
//	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang-shengong",1)
//	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");

	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
