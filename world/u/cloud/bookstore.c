// bookstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "���");
	set("long", @LONG
��������վ�������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/wroad1" ]) );

        set ("objects", ([
	"/u/cloud/npc/book_seller" : 1,  	
	]));
	
	set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����顣\n";
}

