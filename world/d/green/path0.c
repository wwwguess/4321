// Room: /d/green/path0.c

inherit ROOM;

void create()
{
	set("short", "С·�ľ�ͷ");
	set("long", @LONG
С·���������Ժ�������úܲ�����, ���ϻ�������ϡ�������ӵ�
���, ·�����ܳ������Ӳݺ�С��֮���, �����൱�Ļ���. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"north" : "/d/green/cave0",
  "south" : "/d/green/path1",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
