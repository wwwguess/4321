#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "山路" NOR);
	set("long", @LONG
一条山路静静的向远方蜿蜒延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"qinghaihu",
  "south" : __DIR__"rqhhtokl4",
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

