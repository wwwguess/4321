// wizlist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;

	write(MUD_NAME + "Ŀǰ����ʦ�У�\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
	for(int i=0; i<sizeof(list); i++)
		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
	write("\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}
