#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "汉中" NOR);
	set("long", @LONG
这里就是汉中，历来为兵家必争之地。西面就是定军山。
西北就到兰州，东北则往古都长安了。
LONG
	);
	set("exits", ([ 
  "northeast" : "/d/road/rcatolz0",
  "northwest" : __DIR__"rcatolz1",
  "southwest" : __DIR__"rcatojm0",
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

