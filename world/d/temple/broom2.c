// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��ʲôҲû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/broom1",
]));

	setup();
	replace_program(ROOM);
}
