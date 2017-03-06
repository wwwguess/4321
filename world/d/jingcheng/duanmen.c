#include <ansi.h>

inherit ROOM;

void create()
{
 set("short", YEL "端门" NOR);
        set("long", @LONG
 这是端门,这是紫禁城的最后一道防线。高大的城门透露出威严。城门口仍有
很多侍卫把守。再往北就是紫禁城了。
LONG
        );
        set("outdoors", "city");
        set("exits", ([
        "south" : __DIR__"wumen",
        
        ]));
        set("objects", ([
   __DIR__"hchshw1" : 3,
   __DIR__"hchshw2" : 3,
   __DIR__"hchshw3" : 3,
 

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
