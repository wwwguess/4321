// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ƽ����ʯ��·, ������Լ���Կ�����������ĳ���, ����
��������������;�ĵ�·. ������һ����С����ʯ·ͨ������. ������
һ��ʯ��, �ԱߵĿյض���һЩʯ��. �ϱ߿�ȥ��һƬ������. ʯ��·
����������.

LONG
	);
    set("exits", ([
    "west" : __DIR__"path6",
    "north" : __DIR__"path4",
    "east" : __DIR__"station0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
