//ROOM: /d/suzhou/xx2.c
//by dwolf
//97.11.7
 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"С��"NOR);
	set("long", @LONG
	����һ��ͦ���ֵ�С�꣬�����Ϊ������������������԰�ְɡ����Ů��
���������������ר��Ů����Ʒ��С�ꡣ 
LONG	
	);                  
	set("exits", ([
		"south" : __DIR__"xxiang2",
]));
	set("objects", ([
		__DIR__"npc/yfeng" : 1,
		__DIR__"npc/girl" : 2,
]));
	setup();
	replace_program(ROOM);
}
