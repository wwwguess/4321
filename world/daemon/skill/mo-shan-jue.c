//  mo-shan-jue.c  ��ħ���� 
// dfbb@hero
                         

inherit SKILL;

string *dodge_msg = ({
        "$n��Ӱһת��һʽ����������̡����׵رܿ�����һ�С�\n",
        "$n��Ʈ����һʽ��������ת����һ�㣬��һ�٣���������һ�ԡ�\n",
        "����$n��Ӱһ�࣬һʽ�����������С��ڼ䲻�ݷ�֮�ʴ��ݵرܿ�����һ�С�\n",
        "$nһʽ��������������ζ�Ȼ�θߣ�ʹ$N�Ĺ��ƾ�����ա�\n",
        "$n����һ�㣬һʽ�������ž��硹��Ӱ���󻬿����ߣ����˿�ȥ��\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취��ħ������\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("gin") < 20 )
                return notify_fail("��������񲻹���������ħ������\n");
        me->receive_damage("kee", 10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("scholar") + "/mysterrier/" + action;
}
