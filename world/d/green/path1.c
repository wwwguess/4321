// Room: /d/green/path1.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/green/path0",
  "south" : "/d/green/path2",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
