//ROOM:/d/suzhou/yuanlin3.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	����һ�����顢���ֱ���¶��ţ�������ǰ���ֵ������ɷ�ǽ����
�������ܴ��Ĵ��֡����߷ֱ����������ͨ���һ����볤�������������һ������ĵ
���������ע�⣬ֻ���������̣�˿�����ƣ����µ�ɰ��ʮ��Ư����������Сͤ��
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin5",  
		"south" : __DIR__"yuanlin2",
]));
	setup();
	replace_program(ROOM);
}
  

