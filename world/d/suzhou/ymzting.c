// Room: /d/suzhou/ymzting.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"��������"NOR);
        set("long", @LONG
	  ����������������֪������ں����ѺȾƣ�����"��ľ����"�����ر���
����������Ǻ����ˣ���Ů��ס�ţ�����󲻷����ȥ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"yamen",
		"north" : __DIR__"ymhting",
		"east" : __DIR__"shufang",
	]));        
	create_door("south", RED"��ľ����"NOR, "north", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/hu" : 1,
		__DIR__"npc/chu" : 1,
	]));

	setup();
}


