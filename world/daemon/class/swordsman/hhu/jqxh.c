// powerup.c

#include <ansi.h>
inherit SSERVER;
//inherit F_CLEAN_UP;

void remove_effect(object me ,int amount);

int exert(object me, object target)
{
	int i,b;
	string msg;

//	if( target = me ) return notify_fail("�㲻�ܶ��Լ�ʹ����ħ����󷨡�\n");

	if( (int)me->query("force") < 50 )
  	    return notify_fail("�������������\n");
	if( (int)me->query_temp("jqxh") ) 
            return notify_fail("���Ѿ����˹�\���ˡ�\n");
        if( !target ) target = offensive_target(me);
	me->add("force", -50);
	me->receive_damage("kee", 10);

        msg = HIR "$Nʹ���Ӻ��ڹ��ľ���----��ħ����󷨣�\n";
            b=me->query_skill("force");
        if( random(100) <(b/2)) {
        //      msg += "$p���Գ�����\n" NOR;
        //      for (i=0; i<random (3)+1; i++)
        msg+=HIG "$p���һ�����ã���������������к��������\n" NOR;
                  i=target->query("kee");i=i*(b - 40)/650;
              if (i>0) {      target->add("kee",-i);me->add("kee",i);}
                  i=target->query("sen");i=i*(b - 40)/500;
              if (i>0){      target->add("sen",-i);me->add("sen",i);} 
                 i=target->query("gin");i=i*(b - 40)/700;
             if (i>0)  {     target->add("gin",-i);me->add("gin",i);}
        //              COMBAT_D->do_attack(me, target, me->query("weapon"));
                } 
            else {
                msg +=HIB "���Ǳ�$p���ݻ����ˣ�$p���һ��������Ұ����ң�������������\n" NOR;
                        target->kill_ob(me);         
        }
        message_vision(msg, me, target);  
	me->set_temp("jqxh", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 2 :), 2);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}

void remove_effect(object me , int mount)
{
	me->delete_temp("jqxh");
	me->add("dodge",- mount);
//	tell_object(me, "�����а��\������ϣ��������ջص��\n");
}
