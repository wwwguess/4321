// bxlou.c
//by dwolf
          
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"八仙酒楼"NOR);
	set("long", @LONG
	八仙酒楼可是非常出名的一家酒楼，它历史悠久，声誉良好。南来北往的人们
都爱到这儿喝上几杯。现在里面有许多客人，你四处望望，好象已经没有座位了。
LONG
);
	set("exits", ([
		"up" : __DIR__"bxlou2",
		"south" : __DIR__"wroad1",
		"east" : __DIR__"nroad1",
	]));                               
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
		__DIR__"npc/ren" : 2,
	]));
	setup();
	replace_program(ROOM);
}
