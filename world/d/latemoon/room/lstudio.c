#include <room.h>
inherit ROOM;

void create()
{
    set("short", "���鷿");
	set("long", @LONG
����һ�䰲�����鷿, ��������, ��������һ������, �������
����һ�����ٷ���ƽ̨��! ǽ�ϳ���������������, ������һЩ�黭                  
��һ��Ũ�����µ�������Ϣ!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"lcenter",

]));

    set("objects", ([
        __DIR__"npc/old" : 1,
        __DIR__"npc/killer" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
