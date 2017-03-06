//ROOM: d/suzhou/nroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	     ����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ��Եúܷ�æ�� ������
һ�ҹ˿��ڶ�Ĳ�ݣ����̾�����ʿ��������̸��˵�ء�����һ����վ�����߾��ǳ���
�ˣ���ͨ�������ĺ���������·�����˸߲��ҵ����ˡ�
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"chaguan",
		"north" : __DIR__"ngate",
		"south" : __DIR__"nroad1",
		"east" : __DIR__"yizhan",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1,
]));
	
	setup();
}





