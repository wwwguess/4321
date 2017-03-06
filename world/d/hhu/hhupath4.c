// Room: /d/hhu/hhupath4.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    林荫道一边是水利馆，一边是工程馆
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hhupath3",
  "northwest" : __DIR__"hhucross",
]));
	set("no_clean_up", 0);

	setup();
}
