// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�������ʦ������\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}

void skill_improved(object me)
{
	if( (int)me->query("eff_sen") < (int)me->query("max_sen") ) {
		tell_object(me, "�����������ʦ�����гɣ�ʹ�������̨������˼�ǳγ���\n");
		me->set("eff_sen", me->query("max_sen"));
	}
}
