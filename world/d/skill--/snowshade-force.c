// fonxanforce.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_skill_usage(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("��ɽ���ڹ�\ֻ����ѧ�Ļ��Ǵ�����(exert)�����������ȡ�\n");
}