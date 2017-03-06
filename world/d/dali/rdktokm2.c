#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "横断山" NOR);
	set("long", @LONG
这儿就是绵延千里的横断山，山势高而险。往西北望去,
那云雾中的积雪在泛着皑皑白雪，周围寂静无声，风越
刮越大，还是赶快过山吧。
LONG
	);
	set("exits", ([ 
  "northdown"  : __DIR__"rdktokm1",
  "southdown" : __DIR__"rdktokm3",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

