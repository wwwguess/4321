//piaoping-shenfa.c 
//��ƮƼ�� 
//dfbb@hero


inherit SKILL;

string *dodge_msg = ({
	"$nһ�С��紵ƮƼ���������ɵر��˿�ȥ��\n",
	"ֻ��$n����һת��һʽ��ÿ����Ϫˮ����������$N�Ĺ�����\n",
	"$nʹ��������ƻ�����������΢����$N�����˸��ա�\n",
	"$n����һ�˪�����һ�֣�һ�С��������������ѱ��˿�ȥ��\n",
	"����$nʹһ�С��崨���ˡ�����������ɴһ��Ʈ�˿�ȥ��\n",
	"$n��������������બ�Ѿ���һ�С���Ե�ˮľ������������\n",
	"����$nһ�С������޶Ͼ���ʹ��,��Ȼ�Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 50 )
		return notify_fail("�����ѧ����������û�а취��ƮƼ����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 80
	||	(int)me->query("gin") < 80 )
		return notify_fail("��ľ����㪬������ƮƼ����\n");
	me->receive_damage("kee", 10);
	me->receive_damage("sen", 10);
	me->add("force", 3);
	return 1;
}

