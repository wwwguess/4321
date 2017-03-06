#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "青石官道" NOR);
	set("long", @LONG
这是一条青石官道，西面就是大理国了。西南方
的洱海水波澜澜，有几艘渔船正在网鱼。
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"dalicheng",
  "southeast" : __DIR__"road3",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

