// sword.c

#include <ansi.h>

inherit SKILL;

int valid_skill_usage(string usage)
{
	return usage=="array";
}

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) != 8 )
		return notify_fail("���뽣������ˣ���һ����һ�������С�\n");
	message_vision( HIG "$N������������վ���˸���λ������ˡ����뽣�󡹣�\n" NOR, leader);
	return 1;
}
