
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "�����");
	set("long", @LONG
��������ׯ�����������о���, ��Ի�����桹��ǽ�Ͽ̻�������
����������һЩʫ����������ÿһλ��Ůͼ����̬����֮�У�������
Ȼ������������ˣ�����������������貽������Կ�����λʦ��
һ���������صĲ�������������ģ����Щ�貽��һ�ߵ�ͷ��˼Ҫ���
���ã�ʮ�ֵ�Ͷ�롣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"upstar4",

]));

    set("objects", ([
        __DIR__"npc/shinfun" : 1,
    ]) );
    create_door("south","ľ��","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
