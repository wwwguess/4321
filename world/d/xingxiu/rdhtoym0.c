#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "丝绸之路" NOR);
	set("long", @LONG
这里的路更难走了,风沙很大,不时卷起沙石.
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"yumenguan",
  "southeast" : __DIR__"dunhuang",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
	object me = this_player();
	
        return;
}

