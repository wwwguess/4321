#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
这儿是通往大理国的驿道，东面就是昆明，路上
人很多。
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"road2",
  "east" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

