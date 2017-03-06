// Room: /d/suzhou/xx.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;  

void create()
{
	set("short", RED"小巷子"NOR);
	set("long", @LONG
这是一条昏暗的小巷子，里面充满了不祥的气息。听说这儿经常有蒙面人在这里出没，见人就
杀，好吓人喔。你还是别呆在这儿好。这儿一个人影也没有。
LONG
	);

	set("exits", ([
		"west" : __DIR__"w_room",
		"south" : __DIR__"xxiang1",
        ]));      
	set("objects", ([
		__DIR__"npc/mmren" : 1,
]));

	setup();
}

