// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С��϶��¡�������һ�����ŵ���$Nͷ��Խ����\n",
	"$nһʽ����Ůɢ��������ˮ����ɢ��һƬ���꣬$N����Ӱ������˫�ۣ���$n���������\n",
	"$nʹ����֯Ů�ڹ项��ͻȻ�û���һ˫ٻӰ��$N������һ��͸�������\n",
	"$n˫��΢����Ȼ���裬һ�С�˫�����衹����������$N�����У�\n",
	"��$nһʽ��ޥ���·�����������һ̾��˳��$N����ʽƮ������֮�⣡\n"
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�߱������ֻ��Ů�Բ�������\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("������Բ�����û�а취���߱�����衣\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ���̫���ˣ��������߱�����衣\n");
	me->receive_damage("sen", 30);
	return 1;
}

void skill_improved(object me)
{
	if( (int)me->query("per") < (int)me->query_skill("stormdance", 1)/3 ) {
		tell_object(me, "����߱���������������ᵽ��һЩ�ľ����仯���������...\n");
		me->add("per", 1);
	}
}
