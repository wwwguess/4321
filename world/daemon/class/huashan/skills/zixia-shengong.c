// zixia-shengong.c ��ϼ��

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("zixia-shengong", 1);
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100)
                return notify_fail("�����������̫���ˡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ϼ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"zixia-shengong/" + func;
}

