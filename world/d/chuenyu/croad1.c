// croad1.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
��������һ����������ϡ�·�ϳ������·��ϡ�輸�ð�����
����ͨ����ʦ��������ͨ�����չصĴ����
LONG
        );

        set("exits", ([
                "northwest"      : "/d/village/road2",
		"southeast" 	 : __DIR__"croad2" ]) );

/*        set("objects", ([
                "/u/cp/chater2" : 1, ]) );*/
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

