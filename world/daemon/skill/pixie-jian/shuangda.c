//˫��
//write by lysh

#include <ansi.h>

inherit F_SSERVER;
inherit NPC;

int perform(object me, object target)
{
        string msg;
        object weapon;
                        
        if( !target ) 
		return notify_fail("��Ҫ����˭��\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����ʹ������ʹ��˫�򡹡�\n");

	if( me->query_skill_mapped("sword")!="pixie-jian")
		return notify_fail("�����ʹ��а������ʩչ��˫�򡹡�\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
	if( (int)me->query("force") < 50)
		return notify_fail("��������������޷�ʩչ��˫�򡹡�\n"); 

        if( (int)me->query_skill("damo-jian", 1) < 60 )
                return notify_fail("��Ľ���������죬����ʹ�á�˫�򡹡�\n");
        me->add("force", -50);

        msg = CYN "$Nʹ����˫�򡹣�����㹦��$n��\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        
}
