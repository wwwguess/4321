// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
С·�����������������ǳ��˴���. ������һ��СС��������, ��
����һ����լ�ƵĽ���, ������ڲ������. ������һ������·��.

LONG
	);
    set("exits", ([
    "south" : __DIR__"path3",
    "north" : __DIR__"path1",
    "west" : __DIR__"temple0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/kid2" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
