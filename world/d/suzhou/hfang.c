// Room: /d/suzhou/hfang.c
//by dwolf 
//97.11.5

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",MAG"后房"NOR);
	set("long", @LONG
这是镖局总镖头龙五居住的地方。屋子里挂着一些字画。屋子西边放着一张床，床边
挂着一把宝剑。
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
	create_door("south", "花雕门", "north", DOOR_CLOSED);

	setup();
}

