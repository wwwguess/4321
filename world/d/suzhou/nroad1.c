//ROOM: d/suzhou/nroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	     ����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ��Եúܷ�æ������
��һ�������¥�󣬹��š�������ơ����������Ŷ�������һ�����ң�������¥��
���ֲ����������������ǵ�����������ֱʡ����������������㴹�����Ρ�������
һ�����������������������ƣ��Ǿ�������������ͬ�������������ˡ�·����
��Ⱥ���ȥ�������������ˡ�
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"east" : __DIR__"whci",
		"north" : __DIR__"nroad2",
		"south" : __DIR__"shizx",
		"west" : __DIR__"bxlou",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 2, 
]));
	
	setup();
}





