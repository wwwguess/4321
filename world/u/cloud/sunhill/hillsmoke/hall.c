// u/sunhill/hillsmoke/hall.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ɽ���´��");
        set("long", @LONG
������ɽ���µĴ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"yard",
		"southwest" : __DIR__"studyroom",
		"southeast" : __DIR__"bookroom",
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
        "/u/cloud/board/bonze_b"->foo();
}
