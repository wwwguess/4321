// ywgu2.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"药王居"NOR);
	set("long", @LONG
	   你来到药王居，只见一个老者正躺在凉席上养神，见你来了，对你微微
一笑，站了起来。房中没有什么别的东东，不知药王用什么给你做手术。
LONG
	);

	set("exits", ([
		"out" : __DIR__"ywgu.c", 
	 ]));  
	set("objects", ([
		__DIR__"npc/yaow" : 1,
	]));
	setup();
}            
           