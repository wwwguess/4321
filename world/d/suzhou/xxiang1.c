// Room: /d/suzhou/xxiang1.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"小巷子"NOR);
	set("long", @LONG
这是一条昏暗的小巷子，里面充满了不祥的气息。听说有个蒙面人在里面出没，见人就
杀，好吓人喔。你还是别往里边走好。几个地痞正在这儿游荡。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xx",
		"south" : __DIR__"wroad2",
        ]));

	set("objects", ([
		__DIR__"npc/liumang" : 2,
	]));

	setup();
}

