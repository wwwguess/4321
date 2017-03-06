#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "沧州" NOR);
	set("long", @LONG
这里是河北著名武术之乡：沧州。在这儿有个著名的八卦掌
之家，陈八卦。
这儿再往东南走就到济南府了，往北就进入京师。西北则可
到保定、开封。

LONG
	);
	set("exits", ([
  "southeast" : __DIR__"rdktojd0", 
  "north"  : __DIR__"rjdtodk1",
  "southwest" : __DIR__"rjdtodk3",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

