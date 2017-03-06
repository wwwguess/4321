// magic-array.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("tao-mystery") <= (int)me->query_skill("magic-array"))
                return notify_fail("���С��ħ����Ϊ�������޷��������������Ŷݼ�֮����\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("juechen") + "/magic-array/" + spell;
}

int practice_skill(object me)
{
        return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}

