// bxlou2.c
//by dwolf
          
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"八仙酒楼二楼"NOR);
	set("long", @LONG
	八仙酒楼可是非常出名的一家酒楼，它历史悠久，声誉良好。南来北往的人们
都爱到这儿喝上几杯。现在里面有许多客人，你四处望望，好象已经没有座位了。远处
的几个人一看就不是常人，好象有什么秘密。
LONG
);
	set("exits", ([
		"down" : __DIR__"bxlou",
	]));                               
	set("objects", ([
		__DIR__"npc/tianss" : 1,
		__DIR__"npc/tianx" : 1,
]));
	setup();
	replace_program(ROOM);
}
