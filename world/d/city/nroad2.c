// nroad2.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����ʯ�̵صĴ�������ش���ʦ�ı����������뾩�ؾ�
�˵ء�
    �����߾Ϳ��Ե���ʦ�ˡ������������Ⱥɽ��
LONG
        );

        set("exits", ([
                "south"          : __DIR__"nroad1",
                "north"          : "/d/chuenyu/croad3" ]) );

        set("objects", ([
                "/u/cp/chater2" : 1, ]) );
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}

