#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
时常有一匹快马澈鞭而过。原来是官府的捕快正在执行公务！
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"rshgtoft2",
  "south" : __DIR__"rshgtoft0",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

