// Room: /d/hhu/path2.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
这是一条通向河海大学的林荫道
    远远地已经可以看到河海大学的校门了
    四周风景很美。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hhugate.c",
  "east" : __DIR__"path1.c",
]));
	set("no_clean_up", 0);

	setup();
}
