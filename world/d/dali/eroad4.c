#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "盘山小路" NOR);
	set("long", @LONG
周围都是怪石磷磷的石头山，偶尔远方传来一两声猫头鹰叫，
叫人头皮发麻� 好了，前面就是贵阳城了。
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"eroad3",
  "northeast" : "/d/road/guiyang",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

