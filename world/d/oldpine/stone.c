// Room: /d/oldpine/stone.c

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
��������վ��һ��ͻ���Ĵ���ʯ��, ��Ȼ�е㻬, �㻹����վ��,
�����ܿ�, ���˳�������̦��ʯ��, ������·�����ˡ�
LONG
	);

	set("objects", ([
		__DIR__"npc/venomsnake":	1,
	]) );

	setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

int do_climb(string arg)
{
	if (!arg || arg != "down")
		return notify_fail ("������ȥ(down)��\n");

	message_vision ("$NѸ�ٵ����´���ʯ��\n",this_player());
	this_player()->move(__DIR__"cave1");
	return 1;
}

