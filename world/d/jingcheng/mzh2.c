#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"民宅"NOR);
	set("long", @LONG
这是一户长安城里普普通通的民宅，小夫妇俩朴实勤劳，因此，
家境虽然说不上富裕，但也丰衣足食。
LONG         
	);
	set("objects", ([
		__DIR__"npc/liver.c" : 1,
		__DIR__"npc/liver2.c" : 1,
]));
	set("exits", ([ 
 "north" :__DIR__"xw4",
 	]));
	setup();
	
}

