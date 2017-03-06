#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
这是一条驿道，向西北望去可以看到兰州城了，这不由得你精神一震，加快了脚步。

一条驿道静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rcatolz1",
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

