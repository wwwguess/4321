// /d/city/shangshu/huayuan
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long",@LONG
���鸮�Ļ�԰���Ѽ���������󻨻ܡ���������ĵ�������ݵ���
�����㲻�ܲ������������ȫ������ʱ�Ļ��ܾ��࿪���ţ���������
����ζ���ӻ�԰���о�����լ���������ƺ���һ�����ݡ�
LONG
        );

        set("exits", ([
		"north":	__DIR__"road3",
		"east":		__DIR__"neizhai",
		"west":		__DIR__"road4",
                ]));

	set("objects", ([
		__DIR__"npc/gardener":	1,
		]));

	create_door("east", "����", "west", DOOR_CLOSED);

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

