// feilong.c ��ɽ���������������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

	if( !me->query("feilong"))
		return notify_fail("����⹦��û������ܡ�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����ʹ������ʹ�á������������\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( (int)me->query_skill("huashan-jianfa", 1) < 100 )
	        return notify_fail("��Ļ�ɽ����������죬����ʹ�á������������\n");
	
        if( (int)me->query_skill("huashan-neigong",1) < 100 )
                return notify_fail("��Ļ�ɽ�ڹ��ȼ��������޷�ʹ�á�������������С�\n");

        msg = CYN "$Nʹ����ɽ�������С����������������һԾ�������ڿ���һŤ��ˣ��һ����������$nһ㶣�һ������$nǰ�ء�\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")) 
	{
                msg += "���$p��$Pһ������Ҫ�����޷�֧�ţ����ڵ��ϡ�\n" NOR;
	        message_vision(msg, me, target);
//                target->set("max_kee",10);
	        target->unconcious();
        } 
	else 
	{
                msg += "����$p���з��������ɵö㿪�ˡ�\n" NOR;
	        message_vision(msg, me, target);
	        me->start_busy((250-(int)me->query_skill("huashan-jianfa"))/ 30 );
        }

        return 1;
}

