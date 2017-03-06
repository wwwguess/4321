#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "山路" NOR);
	set("long", @LONG
一条蜿蜒的山路静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"road3",
  "east" : __DIR__"road1",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

