//ROOM: /d/suzhou/xxiang2.c
//by dwolf
//97.11.7
 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"С����"NOR);
	set("long", @LONG
	����һ��ͦ���ֵ�С���ӣ������Ϊ�����������������԰�ְɡ��������
����������������һ����Ů����Ʒ��С�꣬������ͨ�����ڹ�ȥ�� 
LONG	
	);                  
	set("exits", ([
		"west" : __DIR__"sroad2",
		"north" : __DIR__"xx2",
]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
	replace_program(ROOM);
}
