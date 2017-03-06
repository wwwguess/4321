//ROOM: /d/suzhou/xxiang2.c
//by dwolf
//97.11.7
 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"小巷子"NOR);
	set("long", @LONG
	这是一条挺热闹的小巷子，大概因为对面就是苏州著名的园林吧。许多游人
来来往往。北边是一家卖女人用品的小店，男人们通常羞于过去。 
LONG	
	);                  
	set("exits", ([
		"west" : __DIR__"sroad2",
		"north" : __DIR__"xx2",
]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
	replace_program(ROOM);
}
