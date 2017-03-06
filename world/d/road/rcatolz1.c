#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "山石官道" NOR);
	set("long", @LONG
一条山石铺就的官道静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"hanzhong",
  "west" : __DIR__"xxroad1",
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

