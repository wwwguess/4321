//ROOM:/d/suzhou/yuanlin4.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	�������ɻ��صĴ����ϣ���ˮ�羧��һ�㱼�룬����������ȥ��ֻ
��ˮ���仨���࣬��ˮ���壬���ܵ����������������ر����д����������ҡ��ӣ���
����հ㣬����һЩ�������ȹ���ȥ��ͨ������Сͤ��
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin2", 
		"east" : __DIR__"yuanlin6",
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,
]));
	setup();
	replace_program(ROOM);
}
  

