// park.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�żһ�԰");
	set("long", @LONG
��������վ���żһ�԰��
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/eroad2" 
        ]) );
        set("objects", ([
                "/u/cloud/npc/thief" : 1,
        ]) );

        setup();

}

