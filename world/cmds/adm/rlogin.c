// rlogin.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( SECURITY_D->get_status(me) != "(admin)" )
		return 0;

	if( !arg ) return notify_fail("你要用谁的身分连线？\n");
	seteuid(getuid());
}
