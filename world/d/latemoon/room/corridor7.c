#include <room.h>

inherit ROOM;

void create()
{
   set("short", "����");
	set("long", @LONG
�����������ӭ�������������������������ȥ��̧ͷһ����
ֻ������ǽ�ڣ�������͸���ٽ��黭������ǽ�ϡ�����ɴ�֣����
��⣬������̤��ש�����Ǳ����仨����һ���飬��һ����������
�ǵ�յ���̴��ڡ�
LONG
	);
    set("exits", ([
    "south" :__DIR__"flower1",
    "east" : "/d/latemoon/room/eroad1",
    "west" : "/d/latemoon/room/wroad2",
    ]));
    set("objects", ([
        __DIR__"npc/yuchoun" : 1,
    ]) );

   create_door("south","������","north", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
