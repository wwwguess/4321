// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��Ϊ��������\n");
	if( (int)me->query("force") < 50 ) // - (int)me->query("max_force") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_kee") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision",
		HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("jiali", 0);
      me->start_busy(4);

	return 1;
}
