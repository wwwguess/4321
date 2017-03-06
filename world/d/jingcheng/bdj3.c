#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"北大街十字路口"NOR);
	set("long", @LONG
这里是北门大街和玄武大街的十字路口。向北可以隐约看见皇宫的
高墙。
LONG
	);

	set("exits", ([
 "north" :__DIR__"wumen",  
 "south" :__DIR__"bdj2",
 "west"  :__DIR__"xw1",
 "east"  :__DIR__"xw5",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

