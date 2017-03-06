//ROOM: d/suzhou/wroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	  ����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش���������,
����Ҳ�������ӡ�������һ�������ľ�¥�������εĴ����Ϸ�д�š����ɾ�¥����
���̽���֣��Ծ����������治ʱ�ش����ƿ��ǵĻ�ȭߺ�������ϱ���һ�Ҵ󻧡�
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad2",
		"north" : __DIR__"bxlou",
		"south" : __DIR__"zuojia",
		"east" : __DIR__"shizx",
]));
	set("objects", ([
		__DIR__"npc/guo" : 1,
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





