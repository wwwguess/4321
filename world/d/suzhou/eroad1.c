//ROOM: d/suzhou/eroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	  ����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش���������,
����ͦ������������һ��Ǯׯ���ϱ���һ�ҵ��̡�������һЩ���ˡ�
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"shizx",
		"north" : __DIR__"qzhuang",
		"south" : __DIR__"dangpu",
		"east" : __DIR__"eroad2",
]));
	set("objects", ([
		__DIR__"npc/ren" : 2,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





