// /d/city/shangshu/yuan

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���鸮ͥԺ");
        set("long",@LONG
���ߵ������鸮��ͥԺ��Ժ�Ӻܴ󣬵���������������һɫ��
����ʯ�̾ͣ���ʾ�����˵����ɡ����ߵĸ���ʱ�����ţ����Ǹ߹ٿ�
������������������˻�͵Ŀ��������е�ʯ·ͨ��ͷ�����������
��ȥ����Ժ��
LONG
        );

        set("exits", ([
                "west" :        __DIR__"gate",
                "east" :        __DIR__"keting",
		"south":	__DIR__"road3",
		"north":	__DIR__"road2",
                ]));
       
	set("outdoors", "city");

        create_door ("west", "������", "east", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( (dir=="east" || dir == "west" )&&  !userp(this_player()))
        return 0;
        
	return ::valid_leave(me,dir);
}

