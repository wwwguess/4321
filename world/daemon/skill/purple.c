// purple.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        int lvl;

        lvl = (int)me->query_skill("purple", 1);

        if( (int)me->query("shen") < 0 )
                return notify_fail("���а��̫�أ��޷���������������\n");

        if(me->query("gender") == "����" && lvl > 39)
                return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");


        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ�ܿ�ѧϰ����ߡ�\n");
}
