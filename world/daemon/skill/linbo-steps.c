// linbo-step.c
//�貨΢��

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С�հ����ǰ���������ɵر��˿�ȥ��\n",
	"ֻ��$n����һת��һʽ���������á���������$N�Ĺ�����\n",
	"$nʹ����΢��������������΢����$N�����˸��ա�\n",
	"$n����һ�˪�����һ�֣�һ�С��������ޡ��ѱ��˿�ȥ��\n",
	"����$nʹһ�С��������ˡ�����������ɴһ��Ʈ�˿�ȥ��\n",
	"$n��������������બ�Ѿ���һ�С��������ӡ�����������\n",
	"����$nһ�С�հ���ں�ʹ������Ȼ�Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 60 )
		return notify_fail("�����ѧ����������û�а취���貨΢����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("gin") < 80
	||	(int)me->query("sen") < 80 )
		return notify_fail("��ľ����㪬�������貨΢����\n");
	me->receive_damage("gin", 10);
	me->receive_damage("sen", 10);
	me->add("force", 3);
	return 1;
}

