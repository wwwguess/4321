// baguabu.c ���Բ�
// written by lysh

inherit SKILL;

string *dodge_msg = ({
	"$nʹ�������־���������Ʈ������̣Ǭλ��ǡ�ö��$Nһ����\n",
	"$n����΢����һ�С����־�������Ȼʹ����˦$Nһ��������λ��ʹ$N������ա�\n",
	"$n����ͻ����һ�С�ˮ�־�������$NҸ���Ƶ�$N��󣬶嵽��λ��\n",
        "$nһ�С����־�������һŤ��Ծ����λ��$N��������������\n",
	"$n����΢�Σ��˺�һ����̣����λ��һ�С����־������պñܿ�$N�Ĺ�����\n",
	"$nһ�С�ɽ�־���������һ�Σ�ٿ��֮�����۽����࣬��̣��λ��ʹ$N���������͡�\n",
        "$n�������㣬����������У�һ�С����־���������������λ��ʹ$N����������ա�\n"

});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("�������̫���ˣ����������Բ���\n");
        me->receive_damage("kee", 20);
        return 1;
}

