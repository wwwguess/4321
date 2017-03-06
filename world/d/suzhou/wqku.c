// ROOM: /d/suzhou/wqku.c
//by dwolf
//97.11.4 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"兵器库"NOR);
	set("long", @LONG
	这里是兵器库，到处银光闪闪，让人眼花缭乱。宝刀、宝剑、大刀、长剑、
哨棒，短刀、短剑、短棍，各色各样的兵器应有尽有，你一时不知道挑什么好。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhuyin",
	]));                 
	set("objects", ([
		__DIR__"npc/obj/tiejia" : 1,
		__DIR__"npc/obj/gangdao" : 1,
		"/clone/weapon/fangtianji" : 1,
                "/clone/weapon/xiangmochu" : 1,
		"/clone/weapon/yinqiang" : 1,  
]));

	create_door("north", "铁门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

