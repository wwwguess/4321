#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
周围的人多起来了，去昆明城的人都在往东南走呢。
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"rdktokm4",
  "southeast" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

