// refresh.c

int exert(object me, object target)
{
	if( target ) return notify_fail("��ֻ�����ڹ�\�ա��Լ�������\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("�������������\n");

	me->receive_heal("sen", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N��һ�������˿����������������Ѷ��ˡ�\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
