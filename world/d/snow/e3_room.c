// Room: /d/snow/e3_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间打扫得相当乾净的客房，虽然所有的家俱看起来都相当朴
素，比不上县城里几家著名的大酒馆，但是自有一种敦厚亲切的感觉，
你在这里相信可以安心的休息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"inn_3f",
	]));
	create_door("west", "房门", "east", DOOR_CLOSED);

	setup();
}
