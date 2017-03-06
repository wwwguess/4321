#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
西北面就是武昌了，路上的人多了起来。
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"wuchang",
  "northeast" : __DIR__"rjjtowc2",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

