// Room: /city/nanmen.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;


void create()
{
     set("short",RED "����" NOR);
	set("long", @LONG
	���������ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬
�ٸ��ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц�����������ƺ�����
��������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"south" : "/d/road/ryytocs0",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

	setup();
}
