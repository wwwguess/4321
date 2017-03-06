//ROOM: d/suzhou/sroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�ϴ��"NOR);
	set("long", @LONG
	    �ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�
Ц�������������������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�
ͣ������һ��������������������԰�֡�����һ��С���ӡ�����С����ߺ������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"yuanlin",
		"north" : __DIR__"sroad1",
		"south" : __DIR__"sgate",
		"east" : __DIR__"xxiang2",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1, 
]));
	
	setup();
}





