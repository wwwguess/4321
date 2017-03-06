#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIR "黄河边" NOR);
	set("long", @LONG
黄河九曲，在这儿的河水还是不算太大，但水流冲刷着岸基，
“唰唰”的声音还是传出很远。再往东南下去一点就是渡口了。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"lzdukoub",
  "northwest" : __DIR__"rdktojyg1",
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

