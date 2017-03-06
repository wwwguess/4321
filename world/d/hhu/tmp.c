// Room: /d/hhu/hohai-room.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "河海馆");
	set("long", @LONG
河海馆是河海大学内的大建筑之一
    有许多教授在此办公。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hhupath2",
  "up" : __DIR__"hohai-room2f",
]));
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/Pro.Zhang" : 1,
]));
       create_door("north","防盗门","south",DOOR_CLOSED);

	setup();
}
