// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
������һ������·��, ������ȥ����һ����С��խ�Ļ���·, ��Ҫ
��·���ϱ����, ������һ����լ.

LONG
	);
    set("exits", ([
    "north" : __DIR__"path2",
    "south" : __DIR__"path4",
    "west" : __DIR__"house0",
    "east" : __DIR__"path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
