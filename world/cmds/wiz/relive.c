inherit F_CLEAN_UP;

#include <dbase.h>
#include <net/dns.h>

mapping skills;

int main(object me, string arg)
{
        string *sk;
        int i;
	object player;

	if ( !arg )
		return notify_fail ("��Ҫ˭��һ�Σ�\n");
 
	if (!objectp(player = new ("/obj/login")))
		return notify_fail ("����newһ��object��\n");

	player->set("id", arg);
	if (!player->restore() )
		return notify_fail ("û������˰���\n");

       if( wizardp(player) || !player->mapp(skills) ) 
		return notify_fail ("����û��Ҫ���\n");

        sk = keys(skills);
	for(i = 0; i<sizeof(sk); i++) {
			skills[sk[i]]++;
                	}

        return 1;
}

