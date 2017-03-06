// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int heal, cost, heal1;

	if( target != me ) return notify_fail("��ֻ�����ڹ�\�����Լ�����Ϣ��\n");

	if( (int)me->query("force") < 20 ) return notify_fail("�������������\n");

	heal1 = (int)me->query("eff_kee") - (int)me->query("kee");

	if( heal1 < 1 ) return notify_fail("������Ѿ��ָ��������ˡ�\n");

//	if( (int)me->query_skill("force") < 1 ) return notify_fail("��ʧ���ˡ�\n");
//	cost = heal * 10 / ((int)me->query_skill("force")/5+1);

	cost = 20;
	if (heal1 > (int)me->query_skill("force")/3+10)
		heal = (int)me->query_skill("force")/3+10;
	else 
		heal = heal1;
 
//	if( (int)me->query("force") < cost ) {
//		heal = heal * (int)me->query("force") / cost;
//		me->set("force", 0);
//		me->receive_heal("kee", heal);
//	} else {
		me->add("force", - cost);
		me->receive_heal("kee", heal);
//	}

	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
