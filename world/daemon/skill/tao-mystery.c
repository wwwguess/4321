// tao-mystery.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

void skill_improved(object me)
{
	me->add("bellicosity", 100); 
}

int practice_skill(object me)
{       
        return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}
