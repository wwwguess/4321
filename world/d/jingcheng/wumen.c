#include <ansi.h>

inherit ROOM;

void create()
{
 set("short", YEL "午门" NOR);
        set("long", @LONG
 这是午门,据说皇帝处死大臣都是在这里砍头。所以置身在这里的确有一种
阴森恐怖的感觉。门口有很多侍卫把守着。再往北就是端门了。
LONG
        );
        set("outdoors", "city");
        set("exits", ([
        "south" : __DIR__"bdj3",
        ]));
        set("objects", ([
   __DIR__"npc/hchshw1" : 3,
   __DIR__"npc/hchshw2" : 3,
   __DIR__"npc/hchshw3" : 3,
 

        ]));
        setup();
}
int valid_leave(object me, string dir)
{
	if( dir == "north" ) { 
		if( present("shi wei", environment(me)) 
		
		)
			return notify_fail(RED"侍卫恶狠狠地说道:皇宫重地，企容尔等擅闯，速速离去,免受皮肉之苦! \n"NOR);
	}
       return :: valid_leave(me, dir);
}          
