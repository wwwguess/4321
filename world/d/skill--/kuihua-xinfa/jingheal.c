// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if ( !wizardp(this_player()) )
		return notify_fail("����Ȩ���о������ƣ�\n");

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("max_force") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("force") < 150 )
		return notify_fail("�������������\n");

	message_vision(
		HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("gin", 10 + (int)me->query_skill("force")/3 );
	target->add("gin", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("gin") > (int)target->query("eff_jing") )
		target->set("gin", (int)target->query("eff_jing"));

	me->add("force", -10);
	me->set("jiali", 0);

	return 1;
}
