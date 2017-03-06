// Room: /d/hhu/hhu1road1.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hhucross",
  "southwest" : __DIR__"hhu1road2",
]));
	set("no_clean_up", 0);

	setup();
}
