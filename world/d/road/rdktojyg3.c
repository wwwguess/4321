#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIY "黄土大道" NOR);
	set("long", @LONG
这是一条用黄土憨就的大道，西北风一刮，常使人灰头灰脑，
一身黄土。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rdktojyg2",
  "northwest" : __DIR__"rdktojyg4",
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

