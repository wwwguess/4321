#include <ansi.h>
inherit ROOM;    

void create()
{
      set("short", HIW"��լ"NOR);
	set("long", @LONG
һ��СС����լ����ɨ�ĸɸɾ������Ҿ㲻�Ǻܺã������۵ľ���һ
�ų����������ķ��ı���īֽ�⣬����һ��С����(paizi)�����Է���
����ľ�Σ�һ��С¯�Ϸ���һ��������ð�ŵ���ˮ����
LONG         
	);
        set("item_desc", ([
		"paizi" : "�ж�����ǿ.\n",
]));    
	set("objects", ([
		__DIR__"npc/liver3.c" : 1,
]));
 
	set("exits", ([ 
 		"west"  :__DIR__"ql3",
 	]));
	setup();
	
}

