// /d/city/shangshu/neizhai
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��լ");
        set("long",@LONG
��������߽����鸮����լ���п�һ���ǲ������˵ġ���լ�Ĳ�
�ú����ţ�һ�еİ��趼�Եú���Ȼ���С���Ȼȥ���Σ���ˮ��ܽ��
������ζ�����߾�������ʱ�����Ļ�԰��
LONG
        );

        set("exits", ([
		"west":		__DIR__"huayuan",
                ]));

	set("objects", ([
		__DIR__"npc/qing_chen":		1,
		]) );

	create_door("west", "����", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

