// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "���������");
	set("long", @LONG
������м��������ᣬ����װ���˲�Ҷ�� 
LONG
        );

        set("exits", ([
                "south"          : "/u/cloud/tearoom",
	]) );

//	set("objects", ([
//	]) );

        create_door("south", "ľ����", "north", DOOR_CLOSED);

        setup();

}


