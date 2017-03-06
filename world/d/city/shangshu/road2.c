// /d/city/shangshu/road2

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",@LONG
���������鸮��С����С�������������ţ�͸����������ԼԼ
�ؿ����Ƕ��ƺ���һ��С�ݡ���������߾���һ��ͷ�����˵�ͷ�
��ס����һλ��͡�����һ���˲��������
LONG
        );

        set("exits", ([
		"north":	__DIR__"road1",
                "east" :        __DIR__"kefang",
		"south":	__DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/huyuan":	1,
		__DIR__"npc/huyuan1":	1,
		]) );

	set("outdoors", "city");
	
	create_door ("east", "ľ��", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir!="south" &&  present("trainer", environment(this_player()))
                && !(string)me->query("marks/����") )
        return notify_fail("��Ժ������ס�����ȥ·���ȵ�����ʲô����\n");

        return ::valid_leave(me,dir);
}


