// kuihua-shengong.c �������� 
// dfbb@hero

inherit FORCE;

string *dodge_msg = ({
        "ͻȻ֮�䣬$n���ϣ���󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
        "$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
        "$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
        "$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",

"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n"
,
        "$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
        "$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
});

int valid_enable(string usage)
{
	return usage == "force" || usage == "dodge";
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
	return notify_fail(" ������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"kuihua-shengong/" + func;
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


