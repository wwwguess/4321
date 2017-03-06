#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "大道" NOR);
	set("long", @LONG
这是一条黄土大道,北风刮来,不时卷起满天黄沙,路边几棵白杨,
却笔直挺拔.往东走就到兰州的黄河渡口了.
LONG
	);
	set("exits", ([ 
  "northwest"  : "/d/road/qinghaihu",
  "east" : __DIR__"rqhhtolz1",
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

