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
  "west"  : __DIR__"rjjtowc2",
  "east" : __DIR__"rjjtowc0",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

