// xiaoyaoyou.c
// written by www

inherit SKILL;

string *dodge_msg = ({
        "$nһ�����໲������������ƮƮ�����$N��һ�С�\n",
        "$n������հ���ʹ��һ�С����ճ��������ܹ���$N�Ĺ�����\n",
        "$nʹ����������ϼ��������΢�Σ�ǡ�ö����$N�Ĺ��ơ�\n",
        "$nʹ�����������᡹����һ��ƮȻ�ݳ��������ŵء�\n",
        "$n������ת��һ�С��������ǡ�ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "ȴ��$nһ���������ա��㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "����$n����Ʈ����ʹ�����������Ρ�����һ�ݣ����ѱܿ���\n",
        "����$n����һ�ã�һ�����������롹��$N��һ�����˸��ա�\n",
        "$n����΢�Σ�һ����ȴ����ɡ��о����յرܿ���$N��һ�С�\n",
});

int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("�������̫���ˣ���������ɽ����\n");
        me->receive_damage("kee", 30);
        return 1;
}

