// invocation.c

inherit SSERVER;

int cast(object me, object target)
{
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ��콫��\n");
	
	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < 60 )
		return notify_fail("��ľ����޷����У�\n");

	message_vision("$N�૵����˼������\n", me);

	me->add("mana", -100);
	me->receive_damage("sen", 60);

	if( random(me->query("max_mana")) < 200 ) {
		message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	if( random(1) )
		soldier = new("/obj/npc/heaven_soldier");
	else
		soldier = new("/obj/npc/hell_guard");

	soldier->move(environment(me));
	soldier->invocation(me);

	return 1;
}
