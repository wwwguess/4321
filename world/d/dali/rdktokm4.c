#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
这里是一条人烟很少的驿道，周围山势连绵，说不定
有强盗出没，还是快走吧。
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rdktokm3",
  "southeast" : __DIR__"rdktokm5",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

