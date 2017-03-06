#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "官道" NOR);
	set("long", @LONG
这是一条青石官道.向西北望去可以看到兰州城了，这不由得你
精神一震，加快了脚步。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rcatolz2",
  "northwest" : __DIR__"lanzhou",
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

