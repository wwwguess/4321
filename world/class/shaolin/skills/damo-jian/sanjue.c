//sanjue.c ��Ħ������

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) 
		return notify_fail("��Ҫ����˭��\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����ʹ������ʹ����Ħ����������\n");

	if( me->query_skill_mapped("sword")!="damo-jian")
		return notify_fail("�����ʹ��Ħ������ʩչ������������\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����Ħ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_dex() < 30)
		return notify_fail("������������޷�ʩչ����Ħ����������\n"); 

        if( (int)me->query_skill("damo-jian", 1) + (int)me->query_skill("sword", 1)/2 < 135 )
                return notify_fail("��Ľ���������죬����ʹ�á���Ħ����������\n");

        if( (int)me->query_skill(me->query_skill_mapped("dodge"), 1) + (int)me->query_skill("dodge", 1)/2 < 135 )
                return notify_fail("����Ṧ�ȼ��������޷�ʹ�á���Ħ����������\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("��Ļ�Ԫһ�����ȼ�����������ʹ�á���Ħ����������\n");

        if( (int)me->query("max_force") < 300 || (int)me->query("force") < 300 )
                return notify_fail("����������㣬�޷�ʹ�á���Ħ����������\n");

	me->add("force", -300);

        msg = CYN "$Nʹ������Ħ��������������㹦��$n��\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        return 1;

}
