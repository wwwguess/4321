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

	tell_object(me, BLU "���еľ��������������ˣ�\n" NOR );
        tell_object(me, HIW "����˸���������ǰ�Ժ���һ�¡�\n"NOR);
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
