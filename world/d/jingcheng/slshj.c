#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�������"NOR);
	set("long", @LONG
����һ���¿��Ų��õ���֡��������������ط���һЩ�ֳ��ľ�
�ᡣ���ӡˢ�鵽���Ƴ����������죬�������������Ҳ���Ų�
��ӡ�ƾ���ͼ�Ĳ�ï��ͼ�顣
LONG         
	);        
	set("objects", ([
		__DIR__"npc/he.c" : 1,
]));

	set("exits", ([ 
 "south":__DIR__"xchjie5", 
 
	]));
	setup();
	
}

