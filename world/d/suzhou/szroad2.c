//ROOM: d/suzhou/szroad2.c
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
�۶���������һ·��������·��������������������֡����߾������ݳ��ˡ�
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"east" : __DIR__"szroad3",
		"west" : __DIR__"szroad1",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
	]));
	setup();
}





