// ninemoonpoison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("gin", 35);
	me->receive_wound("kee", 75);
	me->receive_damage("sen", 5);

	me->apply_condition("ninemoonpoison", duration - 1);

	tell_object(me, BLU "你中的九阴寒冰毒发作了！\n" NOR );
        tell_object(me, HIW "你打了个寒颤，眼前迷乎了一下。\n"NOR);
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
