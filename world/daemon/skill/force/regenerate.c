// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	if (target != me) 
		return notify_fail("��ֻ�����ڹ������Լ��ľ�����\n");

	if (me->query("gin") >= me->query("eff_gin"))
		return notify_fail("�����ھ���ܺá�\n");

	if ((int)me->query("force") < 20)
		return notify_fail("�������������\n");

	me->add("force", -20);
	me->receive_heal("gin", (int)me->query_skill("force") / 3);
	
        message_vision("$N�������˿������ֽŻ�˼��£������˿������л������ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

