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
叫人头皮发麻。
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"eroad4",
  "southwest" : __DIR__"eroad2",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

