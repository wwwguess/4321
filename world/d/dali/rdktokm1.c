#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "横断山北面山脚" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
南方一座大山横在你的面前，这就是横断山。
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"rdktokm0",
  "southup" : __DIR__"rdktokm2",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

