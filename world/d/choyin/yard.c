// Room: /d/choyin/yard.c

inherit ROOM;

void create()
{
	set("short", "ͥԺ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"club",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
