// Room: /city/chaguan.c
// YZC 1995/12/04   
//changed by dwolf
//97.11.7
        
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "如意茶馆");
	set("long", @LONG
	你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里
是个好所在。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"nroad2",
	]));
/*
	set("objects", ([
		__DIR__"npc/kiss" : 1,
	]));
*/
	setup();
}

