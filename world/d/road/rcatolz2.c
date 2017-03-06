#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short", "山脚");
	set("long", @LONG
这里是六盘山的西麓，南面是一片小树林。
LONG
	);
	set("exits", ([ 
  "eastup"  : __DIR__"xxroad3",
  "northwest" : __DIR__"rcatolz3",
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

