//ROOM:/d/suzhou/yuanlin2.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	���߽��¶��ţ�ֻ��ӭ��һ�����֣����ڱ��档ֻ����ʯ�������
���֣��������ޣ��ݺṰ�����ϱ�̦޺�ɰߣ�������ӳ������΢¶��С��������
������֣������Ǻɻ���.
LONG
	);                                        
	set("exits", ([
		"north" : __DIR__"yuanlin3",  
		"east" : __DIR__"yuanlin4",  
		"south" : __DIR__"yuanlin",
]));                                     
	set("objects", ([
		__DIR__"npc/ren" : 2,
]));
	setup();
	replace_program(ROOM);
}
  

