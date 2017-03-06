#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "大运河畔" NOR);
	set("long", @LONG
一条长堤静静的向远方延伸，好象永远没有尽头。
运河中不时有官船运粮通过，传来阵阵吆五喝六的划拳声。
LONG
	);
	set("exits", ([ 
  "south"  : __DIR__"hangzhou.c",
  "north" : __DIR__"rhztosz1",
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

