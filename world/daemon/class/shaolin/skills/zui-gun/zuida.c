//zuida �������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int skill;

        if( !target ) target = offensive_target(me);
			
	if( !(int)me->query_condition("drunk"))
		return notify_fail("��û�к������ʹ�ð������ѽ��\n"); 

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_str() < 25)
		return notify_fail("��ı����������޷�ʩչ�������\n"); 

        if( (int)me->query_skill("zui-gun", 1) + (int)me->query_skill("club", 1) /2 < 90 )
                return notify_fail("��Ĺ���������죬����ʹ�ð������\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("��Ļ�Ԫһ�����ȼ�����������ʹ�ð������\n");

        if( (int)me->query("max_force") < 500 || (int)me->query("force") < 500 )
                return notify_fail("����������㣬�޷�ʹ�ð������\n");

        msg = CYN "$Nҡͷ�����Գ���������ӣ�������ƮƮ�أ�ʹ����������򡹡�\n";

        me->add("force", - 500);
	skill=(int)me->query_skill("zui-gun", 1);
        message_vision(msg, me, target);

        me->add_temp("apply/str", skill/6 + (int)me->query_condition("drunk"));
        me->add_temp("apply/dex", skill/6 + (int)me->query_condition("drunk"));
        me->set_temp("zuida", 1);
        remove_call_out("remove_effect");
        call_out("remove_effect",skill/10 , me, skill/6 + (int)me->query_condition("drunk"));

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/str", - amount);
        me->add_temp("apply/dex", - amount);
        me->delete_temp("zuida");
}
