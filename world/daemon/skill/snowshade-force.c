// snowshade-force.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("��ɽѩӰ�ķ�ֻ����ѧ�Ļ��Ǵ�����(exert)�����������ȡ�\n");
} 
