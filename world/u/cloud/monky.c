// monky.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "իԺ");
	set("long", @LONG
��������վ��իԺ��
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/wroad2" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
		"/u/cloud/npc/monk" : 1,
		"/d/snow/npc/beggar" : 2,
		"/obj/example/dumpling" : 3,
	]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����ơ�\n";
}

