// ROOM: szroad15.c
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
���ݣ��ϱ߲�Զ�����ݡ�һ����ͤ������ǰ�档      
LONG
	);
	set("exits", ([
		"south" : __DIR__"szroad14", 
		"north" : "/d/hangzhou/chting",
]));                            

	setup();
	replace_program(ROOM);
}
