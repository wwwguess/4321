#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"��լ"NOR);
	set("long", @LONG
����һ��������������ͨͨ����լ��С������ʵ���ͣ���ˣ�
�Ҿ���Ȼ˵���ϸ�ԣ����Ҳ������ʳ��
LONG         
	);
	set("objects", ([
		__DIR__"npc/liver.c" : 1,
		__DIR__"npc/liver2.c" : 1,
]));
	set("exits", ([ 
 "north" :__DIR__"xw4",
 	]));
	setup();
	
}

