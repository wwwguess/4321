// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("literate", 1);
	if( s%10==9 && (int)me->query("int") < s/4) {
		tell_object(me, HIW "��������ѧ����������������ˡ�\n" NOR);
		me->add("int", 2);
	}
}
