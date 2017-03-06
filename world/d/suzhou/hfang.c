// Room: /d/suzhou/hfang.c
//by dwolf 
//97.11.5

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",MAG"��"NOR);
	set("long", @LONG
�����ھ�����ͷ�����ס�ĵط������������һЩ�ֻ����������߷���һ�Ŵ�������
����һ�ѱ�����
LONG
	);               
	set("sleep_room", 1);
	set("no_fight", 0);
	set("no_light", 0);
	set("objects", ([
		__DIR__"npc/longwu" : 1,
]));

	set("exits", ([
		"south" :__DIR__"dzju", 
	]));                                
	create_door("south", "������", "north", DOOR_CLOSED);

	setup();
}

