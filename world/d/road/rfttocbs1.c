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
西北方不员有一家客栈。
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rfttocbs2",
  "northeast"  : "/d/xueshan/inn",
  "south" : __DIR__"rfttocbs0",
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

