// croad3.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�������������Ĵ����·���Ӳ�ïʢ�����а��˶�ߣ�������
��϶��������˷��֡�Զ���ɼ�һ��С��ׯ����Χ�ĵ��
    �����Ǿ�ʦ������ͨ�����չء�
LONG
        );

        set("exits", ([
                "northwest"      : __DIR__"croad2",
		"south"	 	 : "/d/city/nroad2" ]) );

/*        set("objects", ([
                "/u/cp/chater2" : 1, ]) );*/
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

