#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG               
这里是青龙大街的中段。西面有一个小门，通向“叶氏草堂”。东
面有一民居，时有行人出入。南面是青龙大街和西长安大街的十字
路口。
LONG
	);

	set("exits", ([
 "north"  :__DIR__"ql2",
 "south"  :__DIR__"xchjie3",
 "west"   :__DIR__"yshct",
 "east"   :__DIR__"mzh4",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

