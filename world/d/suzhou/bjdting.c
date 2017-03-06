// Room: /d/suzhou/bjdting.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"镖局大厅"NOR);
	set("long", @LONG
这是镖局大厅，副总镖头在这儿，一些富人正在这儿和他谈生意。厅内有几张桌子，
几把椅子，桌子上放着些茶，点心。
LONG
	);

	set("exits", ([
		"south" : __DIR__"lwchang",
		"north" : __DIR__"bjhyuan",
	]));

	set("objects", ([
		__DIR__"npc/jiang" : 1,  
		__DIR__"npc/furen" : 2,
	]));

	setup();
	replace_program(ROOM);
}

