// rlogin.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( SECURITY_D->get_status(me) != "(admin)" )
		return 0;

	if( !arg ) return notify_fail("��Ҫ��˭��������ߣ�\n");
	seteuid(getuid());
}
