// Room: /d/snow/w_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间打扫得相当乾净的房间，虽然所有的家俱看起来都相当朴
素。房中光线比较暗，一为相貌普普通通的老者坐在房间的最里面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xx",
	]));
//	set("objects" , ([
//		"/d/zhang/boss":1,
//	]));
//	create_door("east", "房门", "west", DOOR_CLOSED);
	
	setup();
}
