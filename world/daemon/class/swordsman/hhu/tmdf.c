// powerup.c

#include <ansi.h>
inherit SSERVER;
//inherit F_CLEAN_UP;

void remove_effect(object me ,int amount);

int exert(object me, object target)
{
	int i,b;
	string msg;

//	if( target = me ) return notify_fail("你不能对自己使用天魔吸魂大法。\n");

	if( (int)me->query("force") < 50 )
  	    return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("jqxh") ) 
            return notify_fail("你已经在运功\中了。\n");
        if( !target ) target = offensive_target(me);
	me->add("force", -50);
	me->receive_damage("kee", 10);

        msg = HIR "$N使出河海内功的精华----天魔吸魂大法！\n";
            b=me->query_skill("force");
        if( random(100) <(b/2)) {
        //      msg += "$p已显吃力。\n" NOR;
        //      for (i=0; i<random (3)+1; i++)
        msg+=HIG "$p大叫一声不好！精气神正不断外泻！！！！\n" NOR;
                  i=target->query("kee");i=i*(b - 40)/650;
              if (i>0) {      target->add("kee",-i);me->add("kee",i);}
                  i=target->query("sen");i=i*(b - 40)/500;
              if (i>0){      target->add("sen",-i);me->add("sen",i);} 
                 i=target->query("gin");i=i*(b - 40)/700;
             if (i>0)  {     target->add("gin",-i);me->add("gin",i);}
        //              COMBAT_D->do_attack(me, target, me->query("weapon"));
                } 
            else {
                msg +=HIB "但是被$p从容化解了，$p大吼一声：“你敢暗算我？，纳命来！”\n" NOR;
                        target->kill_ob(me);         
        }

	me->set_temp("jqxh", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 2 :), 2);

//	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me , int mount)
{
	me->delete_temp("jqxh");
	me->add("dodge",- mount);
//	tell_object(me, "你的天邪神功\运行完毕，将内力收回丹田。\n");
}
