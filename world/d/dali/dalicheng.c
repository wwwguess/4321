#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
        set("short", RED "�����" NOR);
        set("long", @LONG
������Ǵ�����ˣ�ԶԶ��ȥ��������ΰ��
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

