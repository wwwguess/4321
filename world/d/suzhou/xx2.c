//ROOM: /d/suzhou/xx2.c
//by dwolf
//97.11.7
 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"小店"NOR);
	set("long", @LONG
	这是一条挺热闹的小店，大概因为附近就是苏州著名的园林吧。许多女孩
子来来往往。这店专卖女人用品的小店。 
LONG	
	);                  
	set("exits", ([
		"south" : __DIR__"xxiang2",
]));
	set("objects", ([
		__DIR__"npc/yfeng" : 1,
		__DIR__"npc/girl" : 2,
]));
	setup();
	replace_program(ROOM);
}
