// wu-shun.c
//�Ӻ���ħ��깦
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < ((int)me->query_skill("wu-shun")*50) )
		return notify_fail("���ɱ���������޷������Ӻ���ħ��깦�����衣\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�Ӻ���ħ��깦ֻ����ѧ�Ī����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return CLASS_D("swordsman") + "/hhu/" + func;
}

