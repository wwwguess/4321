// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����������ʯ·��, ������һ������·��. ������һ��
ľ�콨��, �����൱���ƾ�, һƬ��Ҫɢ���Ƶ�ľ���������ſ�, ����
���ּ��Ѿ����Ǻ������. ���Ϲ�ȥ��һ������ʯ��Ĵ�·.

LONG
	);
    set("exits", ([
    "south" : __DIR__"path5",
    "north" : __DIR__"path3",
    "east" : __DIR__"shop0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
