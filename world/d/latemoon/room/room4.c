
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "���鷿");
	set("long", @LONG
����һ�䰲�����鷿, �������С���������һ�����ӣ��������! 
����һ�����ٷ���ƽ̨��! ǽ�ϳ��������������⣬������һЩ�黭 
��һ��Ũ�����µ�������Ϣ! 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "east" :__DIR__"lroad3",

]));

        set("objects", ([
            "/d/latemoon/npc/servant2" : 1,
            __DIR__"npc/spring1" : 1 ]) );
	setup();
	replace_program(ROOM);
}
