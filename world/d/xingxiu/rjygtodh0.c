#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "丝绸之路" NOR);
	set("long", @LONG
丝绸之路在黄土高原上蜿蜒伸向远方.
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"silk2",
  "west" : __DIR__"rjygtodh1",
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

