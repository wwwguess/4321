// u/sunhill/hillsmoke/guestroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���ի");
        set("long", @LONG
������ɽ���µĿͷ���
LONG
        );
        set("exits", ([
                "east" : __DIR__"yard",
        ]));
        set("item_desc", ([
                "sign": @TEXT
�����Ե���ն�������
TEXT
        ]) );

        set("objects", ([
                "/u/cloud/npc/monk_waiter":1,
        ]) );
        setup();
}
