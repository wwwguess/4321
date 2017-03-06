#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "丝绸之路" NOR);
	set("long", @LONG
丝绸之路静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"rjygtodh0",
  "west" : __DIR__"rjygtodh2",
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

