#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"������"NOR);
	set("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬����
�Ľ�������������ӡ������������ȸ�ʽ��������������������
�õ��������졣
LONG         
	);   
	set("objects", ([
		__DIR__"npc/smith.c" : 1,
]));

	set("exits", ([ 
 "north" :__DIR__"xw5",
 	]));
	setup();
	
}

