// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "С·�ľ�ͷ");
	set("long", @LONG
С·���������Ժ�������úܲ�����, ���ϻ�������ϡ�������ӵ�
���, ·�����ܳ������Ӳݺ�С��֮���, �����൱�Ļ���. 
LONG
	);
    set("exits", ([
    "north" : __DIR__"cave0",
    "south" : __DIR__"path1",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
