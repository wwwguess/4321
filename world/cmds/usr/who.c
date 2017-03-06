// who.c
// From ES2
// Modified by Xiang@XKX
//Update by hacky 97-12-16
//��who�Ĺ��ܸ����ˣ����Կ�id��name.

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string name, str, *option;
	object *list;
	int i, j, ppl_cnt;
	int opt_long, opt_id, opt_wiz;

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1;	break;
				//case "-i": opt_id = 1;		break;
				case "-w": opt_wiz = 1;		break;
				default:
					if( wizardp(me)
					&&	option[i][0]=='@' ) {
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
							me, opt_long);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
					return notify_fail("ָ���ʽ��who [-l|-w]\n");
			}
	}

	if( opt_long ) {
		if( (int)me->query("gin") < 30 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("gin", 30);
	}

	str = "�� " + MUD_NAME + "\n";
	str += "��������������������������������������������������������������������������\n";
	list = users();
//	list = sort_array(users(), "sort_user", this_object());
	if( opt_long || opt_wiz ) {
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( !me->visible(list[j]) ) continue;
			if( opt_wiz && !wizardp(list[j]) ) continue;
//                        if ( !wizardp(me) && wiz_level(list[j])!=wiz_level("admin") )  continue;
			str = sprintf("%s%12s %s\n",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->short(1)
			);
		}
	} else {
	
		ppl_cnt = 0;
		j = sizeof(list);
		while ( j-- )
		{
			// Skip those users in login limbo.
			if ( !environment(list[j]) ) continue;
			if ( me && !me->visible(list[j]) ) continue;
			name = sprintf( "%s(%s)", list[ j ]->name( 1 ),
						capitalize( list[ j ]->query( "id" ) ) );
			str = sprintf("%s%-25s%s", str, name,
				(ppl_cnt % 3 == 2 ? "\n" : "") );
			ppl_cnt++;
		}
		if ( ppl_cnt % 3 ) str += "\n";
	}
		
	str +=
		"-------------------------------------------------------------------\n";
	str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, sizeof(list),
		query_load_average() + "\n");

	if ( remote ) return str;

	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;

	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-w]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-w ֻ�г��������е���ʦ��

���ָ� finger
HELP
    );
    return 1;
}
