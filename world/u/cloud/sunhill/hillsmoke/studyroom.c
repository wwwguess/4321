// u/sunhill/hillsmoke/studyroom.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ɽ���µķ��ɣ�
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"hall",
        ]));
        set("item_desc", ([
                "sign": @TEXT
�����Ե���ն�������
TEXT
        ]) );

        set("objects", ([
                "/daemon/class/bonze/master.c":1,
        ]) );
        set("valid_startroom", 1);
        setup();
}
