#include <room.h>

inherit ROOM;

void create()
{
   set("short", "���᷿");
	set("long", @LONG
��������᷿�����������������������ӣ����������������α�
����������һ�Ը߼����ұ߼������������׽���У���߼�����Ҥ��
��ƿ�ڲ�����������颺����������ȥ����Լ�ɿ�����԰��ɫ��.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"wroad2",

]));

       set("objects", ([
        __DIR__"npc/servant" : 1,
        __DIR__"npc/annihi" : 1 ]) );
    create_door("east","���η���","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
