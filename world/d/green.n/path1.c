// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ�������൱������С·, �����Ӳݴ���, ����ܾö�û��������
������. ���Ϻ�Զ�ĵط����Կ������ӵ����, ������·�ƺ����Ǻ���
��.
LONG
	);
    set("exits", ([
    "north" : __DIR__"path0",
    "south" : __DIR__"path2",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
