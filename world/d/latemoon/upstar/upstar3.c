
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��¥����");
	set("long", @LONG
�����ں�����¥�������ϣ�ׯ�������������Ⱥܶ࣬����û�е�
������������·���������ߵ���, �������ɵĳ��Ƽ��Ϲ���һ����
���Ĺ���! ��ҹ֮��ƻ�Ի�! ʮ������!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstar2",
    "north" :__DIR__"upstarc",
    "south" :__DIR__"uproom3",

]));

    create_door("south","ľ��","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
