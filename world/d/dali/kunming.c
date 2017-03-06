#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
        set("short", RED "昆明城" NOR);
        set("long", @LONG
这儿就是昆明城了，远远望去，城门雄伟。
有空可以到城西的西山欣赏落日下的睡美人。
到滇池荡桨也是很有意思的事。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "northwest" : __DIR__"rdktokm5",
        "west" : __DIR__"road1",
        "east" : __DIR__"eroad1",
]));
        set("outdoors", "dali");

        setup();
        replace_program(ROOM);
}                             

void init()
{	
        return;
}

