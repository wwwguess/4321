// Room: /d/suzhou/xx.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;  

void create()
{
	set("short", RED"С����"NOR);
	set("long", @LONG
����һ���谵��С���ӣ���������˲������Ϣ����˵����������������������û�����˾�
ɱ��������ม��㻹�Ǳ��������á����һ����ӰҲû�С�
LONG
	);

	set("exits", ([
		"west" : __DIR__"w_room",
		"south" : __DIR__"xxiang1",
        ]));      
	set("objects", ([
		__DIR__"npc/mmren" : 1,
]));

	setup();
}

