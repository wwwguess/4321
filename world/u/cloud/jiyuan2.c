// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "����Ժ��¥");
	set("long", @LONG
��������Ժ�Ĺ����������������Ʒ������ʫ�����ĵط���������
�š�
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/jiyuan" ]) );

	set("objects", ([
                "/u/cloud/npc/girl" : 1,
	]) );

        setup();

}


