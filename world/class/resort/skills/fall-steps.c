
inherit SKILL;

string *dodge_msg = ({
	"$nһ�С����������Ʒɡ��������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ����ľ���������Ϲ项���ѱ����߳�֮�⡣\n",
	"$nʹ��������������з������������ɵ�������\n",
	"$n����һ�㣬һ�С��������ⲻ�������ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С���¥����÷ںӡ�����������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С������������ز�������������\n",
	"����$nһ�С�������ⷢ���衹ʹ���������Ƶ�$N���ᣡ\n",
        "����$n����Ʈ��������һ�ݣ�һ�С����ּ��Ⱗ��ࡹ���ܿ���һ����\n",
        "$n��������һ�Σ�һ�С���׳��ʱ�����ϺΡ���һ��ת����������֮�⡣\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����粽��\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�������������������������粽����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 40;
}

