//ROOM: d/suzhou/sroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�ϴ��"NOR);
	set("long", @LONG
	    ������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
����������ȥ�����������ֵ������ġ�������һ��������¡�Ŀ�ջ�����Ը��ص�����
������������˵Ҳ�������ǵ��Ļ�ص㡣������һ�Һ���ׯ��
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"mroom",
		"north" : __DIR__"shizx",
		"south" : __DIR__"sroad2",
		"east" : __DIR__"kezhan",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 2,  
]));
	
	setup();
}





