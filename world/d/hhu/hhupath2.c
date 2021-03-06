// Room: /d/hhu/hhupath2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    向南看，有一座高楼: 河海馆(hohai-room)
    四周风景很美。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hohai-room.c",
  "west" : __DIR__"hhupath3",
  "east" : __DIR__"hhupath1",
]));
        create_door("south","防盗门","north",DOOR_CLOSED);

	setup();
        replace_program(ROOM);
}
