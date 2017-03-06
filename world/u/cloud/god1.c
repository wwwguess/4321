// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
    ��������Ǵ��˼��ӵ����ֵĳ�Ժ, ԭ��������ǧ�ܵĲݵأ�
�Ѿ����˾��������ĻĲݳ��ˡ���������һ����ͤ��ͤ���ƺ�Ҳ��Ҫ������...
LONG
        );

        set("exits", ([
                "east"          : "/u/cloud/woodboxy",
	        "west"          : "/u/cloud/god2" ]) );

//	set("objects", ([
//	]) );

        create_door("east", "ľ��", "west", DOOR_CLOSED);

        setup();

}


