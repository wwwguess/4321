// Room: /d/hhu/roadtocenter.c

inherit ROOM;

void create()
{
	set("short", "上坡路");
	set("long", @LONG
这条路通向网络管理中心，那可是河海大学中的通讯枢纽啊！
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"hhupath3",
  "southup" : __DIR__"roadtocenter1",
]));
	set("no_clean_up", 0);

	setup();
}
