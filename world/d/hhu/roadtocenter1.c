// Room: /d/hhu/roadtocenter1.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "上坡路");
	set("long", @LONG
这条路通向网络管理中心，那可是河海大学中的通讯枢纽啊！
    你向南可以看到网络管理中心的大门(door),它经常紧闭着.
    四周风景很美。
LONG
	);
        set("item_desc",([
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hhucenter",
  "northdown" : __DIR__"roadtocenter",
]));
	set("objects", ([ ]));
        create_door("south","防盗门","north",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
}
