// drugstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "ҩ��");
	set("long", @LONG
��������վ��ҩ����
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/nroad1" ]) );

        set("objects", ([
		"/u/cloud/npc/doctor" : 1,
	]) );

        set("no_fight","1");
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д����ҩ��\n";
}

