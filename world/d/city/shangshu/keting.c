// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���鸮����");
        set("long",@LONG
���������鸮�Ļ������ƽ�����˾��ڴ˽Ӵ����ˡ�������װ��
�������࣬�������佲�������еļҾ߶����ó���ľ���ģ�ʱʱ����
һ�ɵ�������ζ���Ҿ߱�����һ����Ⱦ�ģ���������������ԡ�����
����������󣬲������ټ��İ׻�Ƥ��
LONG
        );

        set("exits", ([
                "west" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/shangshu":	1,
		]));

        setup();
        replace_program(ROOM);
}

