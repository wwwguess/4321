#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"�ƾ���լ"NOR);
	set("long", @LONG
�ⶰ���������Ǻܾ�û���˾�ס�ˣ�ǽ�������µ������ǻҡ�����
�����Կ����ʷʵ�����������ȥ��Ժ���Ӳݴ�������������������
�нС�
LONG         
	);  
	set("objects", ([
		__DIR__"npc/rat.c" : 4,
]));
	set("exits", ([ 
 "north" :__DIR__"zhq4",
	]));
	setup();
	replace_program(ROOM);
}

