// daguanming.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("daguanming", 1);
	
	if( (int)me->query("shen") > 100 )
	return notify_fail("�������̫�أ��޷�����������ķ���\n");
		
	if(me->query("gender") == "����" && lvl > 39)
		return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");
		
	if(me->query("family/family_name")!="�������")
		return notify_fail("������"+RANK_D->query_respect(me)
			+"����������еĹ���,��������\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("������ķ�ֻ�ܿ�ѧϰ����ߡ�\n");
}
