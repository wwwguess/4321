// Room: /u/k/karrimor/temple/restroom.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
����һ�乩��ͻ���������ͬ����Ϣ�ҵ��Ŀͷ�, ������ֻ�Ǽ�
���ذڷ��������Ҿ㡣�����ߵ��쾮��, ����������Ļ��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"corridor7",
]));

        set("objects", ([
            "/d/temple/npc/old_taoist" : 1 ]) );

        create_door("west", "ľ��", "east");

	setup();
}
