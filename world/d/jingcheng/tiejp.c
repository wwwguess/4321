#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"铁匠铺"NOR);
	set("long", @LONG
这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子
的角落里堆满了象斧子、铁锤、长剑等各式铁器，叮叮当当的声音
敲得满屋子响。
LONG         
	);   
	set("objects", ([
		__DIR__"npc/smith.c" : 1,
]));

	set("exits", ([ 
 "north" :__DIR__"xw5",
 	]));
	setup();
	
}

