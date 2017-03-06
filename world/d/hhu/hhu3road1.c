// Room: /d/hhu/hhu3road1.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    往西北可以看到河海体育场，
    东南方向是河海大学的交通中心。
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hhucross",
  "northwest" : __DIR__"hhusport",
]));
	set("no_clean_up", 0);

	setup();
}
