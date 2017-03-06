#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "叉口" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
东北就进成都了；西南方向是到唐门。
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"chengdu",
  "west" : __DIR__"rcdtojs1",
  "southwest"	: "/d/tangmen/road1",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
return;
}

