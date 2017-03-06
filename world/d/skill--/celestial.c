// celestial.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_skill_usage(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("��а��\ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

int exert_function(object me, string arg)
{
	string func, target;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("����û�� " + target + "��\n");
	} else 
		func = arg;
	if( file_size(__DIR__"celestial/" + func + ".c") < 0 )
		return notify_fail("����ѧ���ڹ�\û�����ֹ�\�ܡ�\n");
	else
		return (int)call_other(__DIR__"celestial/" + func, "exert", me, target_ob);
}
