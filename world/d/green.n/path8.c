// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ��СС�����ӣ�����������ʯ�ͻ������ϱ�����һ����������
���Ϸ������ӳ��ڲ�����ߡ��������Կ���һ��СС�Ĺ㳡����������һ
������·�ڡ�
 
LONG
	);
    set("exits", ([
    "west" : __DIR__"path3",
    "north" : __DIR__"house1",
    "east" : __DIR__"field0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/kid3" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
