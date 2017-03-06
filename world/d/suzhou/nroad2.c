//ROOM: d/suzhou/nroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"北大街"NOR);
	set("long", @LONG
	     这是一条宽阔的青石街道，向南北两头延伸。南边显得很繁忙。 西边是
一家顾客众多的茶馆，三教九流人士都在那里谈天说地。东边一座驿站。北边就是城门
了，可通向著名的杭州西湖。路上是兴高采烈的游人。
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





