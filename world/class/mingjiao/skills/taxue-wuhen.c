// taxue-wuhen
// yuer

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С���������������Ȼ����Ӱһ����,$N�Ĺ�������ţ�뺣��$nȴ��վ��ԭ�ء�\n",
	"$nһ������ʹ�������䣬������,������ͬ����һ�����˳��������⣬�ܿ���$N��
�������ơ�\n",
	"$nʹ��������˼��������Ȼ����˼���һ��Ծ�����ܿ���$N�Ĺ��ơ�\n"
});

int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("�������̫���ˣ�������̤ѩ�޺ۡ�\n");
        me->receive_damage("kee", 30);
        return 1;
}


