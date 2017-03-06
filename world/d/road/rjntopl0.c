#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
往北你可以看到连绵不断的山脉，那就是五岳之首的泰山。
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"jinan",
  "east" : __DIR__"rjntopl1",
  "northup" : "/d/taishan/daizong",
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

