#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "横断山南面山脚" NOR);
	set("long", @LONG
啊，终于过了横断山了。如果要再过一次可不容易。
LONG
	);
	set("exits", ([ 
  "northup"  : __DIR__"rdktokm2",
  "south" : __DIR__"rdktokm4",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

