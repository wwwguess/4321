// Room: /d/oldpine/cliff2.c

inherit ROOM;

void create()
{
	set("short", "ɽ���ϵ�խѨ");
	set("long", @LONG
��������������һ��ɽ������ǿ��������һ������Ϣ����Ѩ�У���
����������Ҫ������������������һ�β���̵ľ��룬�����ЪһЪ��
���������ߡ�
LONG
	);
	set("outdoors", "oldpine");

	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if( !arg || (arg!= "up" && arg!="down") )
		return notify_fail("��Ҫ����(up)������������(down)��\n");

	if( arg=="up" ) {
		message_vision("$N�����Խűߵ���ʯ�Ȳ��ȣ���ʼС�����������������\n",
			this_player() );
		this_player()->move(__DIR__"cliffdown");
	} else if( arg=="down" ) {
		message_vision("$N�����Խűߵ���ʯ�Ȳ��ȣ���ʼС���������ɽ����������ȥ��\n",
			this_player() );
		this_player()->move(__DIR__"epath3");
	}
	return 1;
}

