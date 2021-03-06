// jieti.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能用天魔大法提升自己的战斗力。\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("jieti") ) return 
notify_fail("想死啊,你已经解体一次了\n");

        skill = me->query_skill("force")+me->query_skill("tianmo-dafa");

        me->add("force", -100);
	me->set("eff_qi",me->query("eff_qi")/10);
        me->set("kee",me->query("kee")/10);
	me->set("gin",me->query("gin")/10);
	me->set("eff_jing",me->query("eff_jing")/10);

        message_vision(
                HIR 
"$N运起天魔解体大法，吐出一大口鲜血！全身一阵乱响.\n" NOR, me);

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
        tell_object(me, "你的天魔解体大法已经失效,真元严重受损!!!\n");
}
 
