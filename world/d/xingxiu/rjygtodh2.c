#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "丝绸之路" NOR);
	set("long", @LONG
西面的树木渐渐多了起来,快到丝绸之路上的小镇敦隍了.
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"rjygtodh1",
  "northwest" : __DIR__"dunhuang",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
	object me = this_player();
	
        return;
}

