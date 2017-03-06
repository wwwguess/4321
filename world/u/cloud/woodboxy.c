// woodboxy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�ײ���");
	set("long", @LONG
��������վ�ڹײ�����
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "east"          : "/u/cloud/nwroad2",
                "west"          : "/u/cloud/god1"
                      ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        create_door("west", "ľ��", "east", DOOR_CLOSED);
        set("objects", ([
                "/u/cloud/npc/box_boss" : 1,
		"/u/cloud/npc/box_waiter" : 8,
 ]) );
        setup();

}

string look_sign(object me)
{
        return "����д�����ס�\n";
}

