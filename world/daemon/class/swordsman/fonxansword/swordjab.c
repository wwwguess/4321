// swordjab.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int i;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	msg = CYN "$Nʹ����ɽ���������־�������һ������������$n��";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*2/3 ) {
		msg += "$p���Գ�����\n" NOR;
		for (i=0; i<random (3)+1; i++)
			COMBAT_D->do_attack(me, target, me->query("weapon"));
		} 
	    else {
		msg += "$p���ݻ���\n" NOR;
		}
	message_vision(msg, me, target);

	me->add("eff_kee",  -10);

	return 1;
}
