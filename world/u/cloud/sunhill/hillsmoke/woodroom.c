// u/sunhill/hillsmoke/woodroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
������ɽ���µĲ񷿣�
LONG
        );
        set("exits", ([
                "west" : __DIR__"yard",
        ]));

        set("objects", ([
                "/u/cloud/npc/monk_guard":1,
        ]) );
        setup();
}
