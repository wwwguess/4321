// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "С�㳡");
	set("long", @LONG
����һ��СС�Ĺ㳡�����������и�����Ĵ�ʯ�顣�㳡��Χ�м���
���ӣ����������ϱ��Ƕ�ľ����Ϊ�ر�������һ��խխ��С���ӣ�����
������������ʯ���Ŀյء�������һ�ô���������һ����ͤ������ڹ㳡
�ϡ�
 
LONG
	);
    set("exits", ([
    "west" : __DIR__"path8",
    "south" : __DIR__"house4",
    "north" : __DIR__"house2",
    "east" : __DIR__"field1",
]));

	setup();
	replace_program(ROOM);
}
