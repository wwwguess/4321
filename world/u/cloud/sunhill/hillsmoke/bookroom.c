// u/sunhill/hillsmoke/bookroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
������ɽ���µĲؾ���
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"hall",
        ]));
        set("item_desc", ([
                "sign": @TEXT
�����Ե���ն�������
TEXT
        ]) );

        set("objects", ([
                "/u/cloud/npc/monk_guard":1,
        ]) );
        setup();
}
