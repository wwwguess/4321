#include <room.h>

inherit ROOM;

void create()
{
   set("short", "��������");
	set("long", @LONG
ͨ���� ������ ����������Ժ��������Ϊ��Ů֮���ޣ�����Ů
�˾��С����Ų��������Ų�������������Ƕ��ſ���Ϊ��Ů����
����ԺΪׯ��Ů�����᷿������԰������һ��С�ţ�Ϊׯ�ڸ�����
ԡ��С���ء������Ͻ����˺��Ҵ��롣
LONG
	);
    set("exits", ([
     "north" :__DIR__"corridor7",
     "east" :__DIR__"bathroom1",
    ]));
    set("objects", ([
        __DIR__"npc/shaoin" : 1,
    ]) );

     create_door("north","������","south", DOOR_CLOSED);
     create_door("east","С����","west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
