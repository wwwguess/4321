// Room: /d/hhu/uproad.c

inherit ROOM;

void create()
{
	set("short", "上坡路");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"hhucross",
  "northup" : __DIR__"uproad1",
]));
	set("no_clean_up", 0);

	setup();
}
