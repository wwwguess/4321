#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "north"  : "/d/road/ryytocs1",
  "southeast"  : "/d/yulan/road",
//  "southwest"  : "/d/moon/croad1",
  "south" : "/d/road/changsha",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

