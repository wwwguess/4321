#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
        set("short", RED "大理城" NOR);
        set("long", @LONG
这儿就是大理城了，远远望去，城门雄伟。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
      //  "northwest" : __DIR__"rdktokm5",
        "west" : __DIR__"west_door",
        "east" : __DIR__"road4",
]));
        set("outdoors", "dali");

        setup();
        replace_program(ROOM);
}                             

void init()
{	
        return;
}

