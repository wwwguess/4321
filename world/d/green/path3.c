// Room: /d/green/path3.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
������һ������·��, ������ȥ����һ����С��խ�Ļ���·, ��Ҫ
��·���ϱ����, ������һ����լ.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/green/path2",
  "south" : "/d/green/path4",
  "west" : "/d/green/house0",
  "east" : "/d/green/path8",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
