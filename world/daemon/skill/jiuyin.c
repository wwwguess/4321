inherit FORCE;

 string *absorb_msg = ({
        "$n������ת��˫��΢�����޼᲻�ݵľ��������ȶ�����\n",

        "$nʩչ�������񹦣����������纮����\n",

        "$n����΢չ�������񹦳��������ռ䡣\n",

        "$n����һ������ǿ����ǿ������ɽ�ڣ���������ȫ��\n", 

        "$n����һ�������������ᣬ�����մ󽭣���������ȫ��\n",

        "$n����Ĭ����Ժ������Զ���������һ������\n",
        });
 int valid_enable(string usage)
{
return usage == "force" || usage == "iron-cloth";
}

int valid_learn(object me)
{
	int i, nf;
	nf = (int)me->query_skill("force", 1);


	if ( nf < 20)
		return notify_fail("��Ļ����ڹ���򻹲������޷���������֮���硣\n");


	return 1;
}


int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyin/" + func;
}
 query_absorb_msg(string limb)
{
       return absorb_msg[random(sizeof(absorb_msg))];
}
