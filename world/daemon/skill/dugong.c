// dugong.c 
//written by tang

inherit SKILL;

int valid_learn(object me)
{
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("����ֻ����ѧ(learn)�������������ȡ�\n");
}


/*string exert_function_file(string func)
{
        return __DIR__"dugong/" + func;
} */