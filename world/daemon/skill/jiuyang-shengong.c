// kuihua-shengong.c �������� 
// dfbb@hero

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
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");

	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 20)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("������������������񹦡�\n");

	me->receive_damage("kee", 10);
	me->receive_damage("force", 10);
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
 query_absorb_msg(string limb)
{
       return absorb_msg[random(sizeof(absorb_msg))];
}


