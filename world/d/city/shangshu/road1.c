// /d/city/shangshu/road1

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",@LONG
���鸮��С���ߵ����ƺ����˾�ͷ��С���Ķ�����һ��С�ݣ�ƽ
ʱ�������ǹصģ�ÿ�찴ʱ��һ���������Ƶ������ͷ���ȥ��������
һ�Ų������ڡ��ϱ߲�Զ���������鸮ͥԺ�ˡ�
LONG
        );

        set("exits", ([
                "east" :        __DIR__"xiaowu",
		"south":	__DIR__"road2",
                ]));

	set("objects", ([
		__DIR__"npc/huyuan":	1,
		]) );

	set("outdoors", "city");
	
	create_door ("east", "Сľ��", "west", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

