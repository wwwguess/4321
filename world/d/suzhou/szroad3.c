//ROOM: d/suzhou/szroad3.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	    ������һ����������Ĵ�����ϡ��������������������ӵ����̣�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"szroad2",
		"east" : __DIR__"szroad4",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
	]));
	setup();
}





