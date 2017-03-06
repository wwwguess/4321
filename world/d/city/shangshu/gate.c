// /d/city/street5

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���鸮����");
        set("long",@LONG
���������鸮���š�����������һ��ܴ�ĺ�ɫ���ң���������
��д���������֡����鸮���������ϵ�һ��С�ֱ������ǵ��������
�⣬���Կ���������Ժա�
LONG
        );

        set("exits", ([
                "west" :        "/d/city/street3",
                "east" :        __DIR__"yuan",
                ]));

	set("objects", ([
		__DIR__"npc/guard":	1,
		]));

        set("outdoors", "city");

	create_door ("east", "������", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir=="east" &&  present("guard", environment(this_player()))
		&& !(string)me->query("marks/����") )
        return notify_fail("�ŷ�������ס�����ȥ·���ȵ�����ʲô����\n");

	if ((string)me->query("marks/����") )
		me->set("marks/����",0);
        return ::valid_leave(me,dir);
}

