// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��������¥");
	set("long", @LONG
���ǲ�¥�Ķ��㣬����������ī�ͳ�ϲ���ڴ�Ʒ��������
    ���װ��Ÿ����̡�
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/tearoom" ]) );

	set("objects", ([
                "/u/cloud/npc/chess_player" : 1,
	]) );

        setup();

}


