
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
    "west" :__DIR__"upstar1",
    "south" :__DIR__"upstarc",
    "north" :__DIR__"uproom2",

]));

    create_door("north","ľ��","south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
