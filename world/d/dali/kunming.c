#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
        set("short", RED "������" NOR);
        set("long", @LONG
��������������ˣ�ԶԶ��ȥ��������ΰ��
�пտ��Ե���������ɽ���������µ�˯���ˡ�
����ص���Ҳ�Ǻ�����˼���¡�
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

