// forest3.c
//by dwolf

#include <ansi.h>
inherit ROOM;

string* npcs = ({
	"pig",
	"snake",
	"tiger",
});

void create()
{       
	int i = random(sizeof(npcs));
	set("short", BLK"森林"NOR);
	set("long", @LONG
	  这里的一切都是静止的，连树叶也静止不动，空气中弥漫着一种神秘气息
。你身边有一残旧的路标牌，你才庆幸找到路时，却发现它指着地，是不是预示着每
一个来这里的人都会走向地狱？
LONG
	);

	set("exits", ([
		"east" : __DIR__"forest2.c",
		"south" : __DIR__"start.c",
		"west" : __DIR__"forest1.c",
		"north" :__DIR__"forest4.c",
	 ]) );

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1]));
	setup();       
}                                  
