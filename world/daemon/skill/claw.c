// claw.c

#include <ansi.h>

inherit SKILL;

void skill_improved(object me)
{
	int s;

	s = me->query_skill("claw", 1);
	if( s%10==9 && (int)me->query("str") < s/4) {
		tell_object(me, HIW "由於你勤练武艺，你的手法更灵活了。\n" NOR);
		me->add("str", 1);
	}
}
