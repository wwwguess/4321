//ROOM: d/suzhou/szroad1.c
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
		"east" : __DIR__"szroad2",
		"west" : __DIR__"egate",
	]));
	set("objects", ([
		__DIR__"npc/ren2" : 1,
	]));
	setup();
}





