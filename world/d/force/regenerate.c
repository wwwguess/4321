// regenerate.c

inherit SSERVER;

int exert(object me, object target)
{
	int heal, heal1, heal2, cost=20;

	if( target != me ) return notify_fail("��ֻ�����ڹ�\�ָ��Լ��ľ�����\n");

	if( (int)me->query("force") < 20 ) return notify_fail("�������������\n");

	heal1 = (int)me->query("eff_gin") - (int)me->query("gin");

	if( heal1 < 1 ) return notify_fail("��ľ����Ѿ��ָ��������ˡ�\n");

//	if( (int)me->query_skill("force") < 1 ) return notify_fail("��ʧ���ˡ�\n");
//	cost = heal * 10 / ((int)me->query_skill("force")/5+1);

	heal2 = (int)me->query_skill("force")/3 + 10;
	heal = (heal1 - heal2) ? heal2 : heal1;

//	if( (int)me->query("force") < cost ) {
//		heal = heal * (int)me->query("force") / cost;
//		me->set("force", 0);
//		me->receive_heal("gin", heal);
//	} else {
		me->add("force", - cost);
		me->receive_heal("gin", heal);
//	}

	message_vision("$N��������˿������ֽŻ�˼��£��������л������ˡ�\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
