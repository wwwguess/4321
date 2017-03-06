// Room: /d/hhu/hohai-room3f.c

inherit ROOM;

void create()
{
	set("short", "河海馆");
	set("long", @LONG
河海馆是河海大学内的大建筑之一
    这是校长的办公室，闲人不得随便出入。
LONG
	);
        set("no_fight","1");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hohai-room2f",
]));
	set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/chairman" :1,
]));
	set("no_clean_up", 0);

	setup();
}
