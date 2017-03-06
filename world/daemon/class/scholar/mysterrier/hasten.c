// hasten.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int count;

	if( !me->is_fighting() )
		return notify_fail("���������衹ֻ����ս����ʹ�á�\n");

	if( (int)me->query("kee") < 70 ) return notify_fail("�����������\n");
	if( (int)me->query("force") - (int)me->query("max_force") < 70 )
		return notify_fail("�������������\n");

	msg = HIY "$Nʹ�������߾���һʽ���������衹������Ȼ�ӿ죡\n" NOR;

	message_vision(msg, me);
	count = (int)me->query_skill("mysterrier") / 20 + 2;
	if( count > 7 ) count = 7;
	while( count-- ) {
		object ob;

		me->clean_up_enemy();
		ob = me->select_opponent();
		if( !ob || (environment(ob) != environment(me))) {
			message_vision(CYN "$N������ת�˼�ת��ٿ��ͣס�˽Ų���\n" NOR, me);
			break;
		} else
			message_vision(CYN "$NѸ�����׵���$n��������һȦ ...\n" NOR, me, ob);

		if( !COMBAT_D->fight(me, ob) )
			message_vision(CYN "����$N�Ҳ���������֣�\n" NOR, me);
		me->receive_damage("kee", 10);
		me->add("force", -10);
	}

	me->start_busy(2);
	return 1;
}
