// unarmed.c

#include <ansi.h>

inherit SKILL;

void skill_improved(object me)
{
	int s;

	s = me->query_skill("unarmed", 1);
	if( s%10==9 && (int)me->query("str") < s/4) {
		tell_object(me, HIW "������������գ������������ˡ�\n" NOR);
		me->add("str", 2);
	}
}
