// Room: /d/hhu/downroad.c

inherit ROOM;

void create()
{
	set("short", "下坡路");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    向西南下坡可到河海西门，
    向东北上坡可到河海大学交通中心，
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hhu1road2",
  "southwest" : __DIR__"hhu1road3",
]));
	set("no_clean_up", 0);

	setup();
}
