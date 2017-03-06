// concentrate.c

#include <ansi.h>

int exert(object me, object target)
{
	int mana_gain;

	if( target ) return notify_fail("���������ֻ�������ָ��Լ��ķ�����\n");

	if( (int)me->query("force") < 30 )
		return notify_fail("�������������\n");

	
	mana_gain =  10 + (int)me->query_skill("force")/5;
	if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
		me->set("mana", (int)me->query("max_mana"));
	else
		me->add("mana", mana_gain);
	me->add("force", -30);
	me->receive_damage("sen", 10);

	message_vision(
		HIY "$N��Ŀ�����ù�\���ķ���������ת��һ�Ρ��������...\n"
		"һ��������$N����ɢ���������$P�Ķ��ģ�Ȼ�󻺻���ȥ��\n" NOR, me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
