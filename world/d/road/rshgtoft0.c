#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
一条驿道静静的通向远方，旁边有很多的茶馆。时常有一匹匹快马撤鞭而过，原来是官府的捕快在执行为
看到一个小村落。
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rshgtoft1",
  "south" : __DIR__"shanhaiguan",
//  "northwest" : "/d/snow/sroad1",
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

