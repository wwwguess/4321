//ROOM: d/suzhou/eroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>   
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	   ����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����
ϡ�٣������ĵغ������塣����Զ���������������ϱ��Ǳ�Ӫ�����߾��������ˡ�
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"eroad1",  
		"north" : __DIR__"yamen",
		"south" : __DIR__"bingyin",
		"east" : __DIR__"egate",
]));                                     
	setup();
}





