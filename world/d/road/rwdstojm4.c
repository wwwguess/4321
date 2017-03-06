#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "三岔路" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
往东北方向走就是到著名的武当山。南面就是剑门关。
LONG
	);
	set("exits", ([ 
  "south"  : __DIR__"jianmenguan",
  "north"  : __DIR__"rcatojm2",
  "northeast" : __DIR__"rwdstojm3",
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

