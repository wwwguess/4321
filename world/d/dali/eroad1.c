#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "昆明城东" NOR);
	set("long", @LONG
这儿是昆明城东，往东走就是到贵阳的山路了。
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"eroad2",
  "west" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

