#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "金沙江畔" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "northwest"  : "/d/road/jsdukoux",
  "southeast" : __DIR__"rdktokm1",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

