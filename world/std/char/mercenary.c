// mercenary.c

#include <dbase.h>

int accept_order(object me, string verb)
{
	if( (string)me->query("id") != (string)query("boss_id") ) return 0;
	switch(verb) {
		case "apprentice":
			command("say �Բ�����������ʦ�У�������ʦ���棡");
			return 0;
		default:
			return 1;
	}
}

int accept_info(object me, string verb)
{
	return (string)me->query("id")==(string)query("boss_id");
}
