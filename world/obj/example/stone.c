// stone.c

inherit ITEM;

void create()
{
	set_name("����ʯ", ({ "stone" }) );
	set_weight(100);
	set("unit", "��");
	set("long", "һ�ź������۵�ʯͷ�������������ú�顣\n");
	set("value", 10);
}

void init()
{
	object env;

	env = environment();
	if( this_player()==env ) call_out( "more_heavy", 100 );
	else remove_call_out("more_heavy");
}

void more_heavy()
{
	set_weight( weight() * 2 );
	tell_object( environment(), "����ú���ʯ������һ�£������ֱ����ˡ�\n");
	call_out( "more_heavy", 100 );
}

void owner_is_killed()
{
	set_weight(100);
}
