// jieti.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return 
notify_fail("��ֻ������ħ�������Լ���ս������\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("�������������\n");
        if( (int)me->query_temp("jieti") ) return 
notify_fail("������,���Ѿ�����һ����\n");

        skill = me->query_skill("force")+me->query_skill("tianmo-dafa");

        me->add("force", -100);
	me->set("eff_qi",me->query("eff_qi")/10);
        me->set("kee",me->query("kee")/10);
	me->set("gin",me->query("gin")/10);
	me->set("eff_jing",me->query("eff_jing")/10);

        message_vision(
                HIR 
"$N������ħ����󷨣��³�һ�����Ѫ��ȫ��һ������.\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/dodge", skill/2);
        me->set_temp("jieti", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("jieti");
        tell_object(me, "�����ħ������Ѿ�ʧЧ,��Ԫ��������!!!\n");
}
 
