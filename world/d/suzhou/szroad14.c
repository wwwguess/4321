// ROOM: szroad14.c
//by dwolf
//97.11.8
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long",  @LONG
	  ����һ����ʯ�����ֱͨ�ϱ������Դ��ⰻȻ������һЩ��֪����С����
��ղ�ʱ�м�ֻС��ɹ������ǲݴ��о���һֻҰ�ã��ɿ�����ˡ����߲�Զ����
���ݣ��ϱ߲�Զ�����ݡ�      
LONG
	);
	set("exits", ([
		"south" : __DIR__"szroad13", 
		"north" : __DIR__"szroad15",
]));                            
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));
	setup();
	replace_program(ROOM);
}
