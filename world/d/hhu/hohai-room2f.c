// Room: /d/hhu/hohai-room2f.c

inherit ROOM;

void create()
{
	set("short", "河海馆");
	set("long", @LONG
河海馆是河海大学内的大建筑之一
    有许多教授在此办公。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hohai-room3f",
  "down" : __DIR__"hohai-room",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/Pro.Wang" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
